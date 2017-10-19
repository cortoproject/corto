/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <corto/corto.h>

/* Free all entityscriptoins, but do not free corto_entityAdmin itself so
 * it can be reused when a thread needs to copy global entities */
static void corto_entityAdmin_freeEntities(corto_entityAdmin *data) {
    corto_int32 depth, sp;

    for (depth = 0; depth < CORTO_MAX_SCOPE_DEPTH; depth ++) {
        for (sp = 0; sp < data->entities[depth].length; sp++) {
            corto_entityPerParent *entityPerParent = &data->entities[depth].buffer[sp];
            corto_dealloc(entityPerParent->entities.buffer);
        }
        corto_dealloc(data->entities[depth].buffer);
        data->entities[depth].buffer = NULL;
        data->entities[depth].length = 0;
    }
}

/* Free all data when thread shuts down */
void corto_entityAdmin_free(void *admin) {
    corto_entityAdmin *data = admin;
    if (data) {
        corto_entityAdmin_freeEntities(data);
        corto_dealloc(data);
    }
}

/* Copy data from global admin to (local) thread admin */
static corto_int16 corto_entityAdmin_copyIn(corto_entityAdmin *src, corto_entityAdmin *dst) {
    corto_int32 depth, sp;

    if (src->count) {
        if (corto_rwmutex_read(&src->lock)) {
            goto error;
        }

        for (depth = 0; depth < CORTO_MAX_SCOPE_DEPTH; depth ++) {
            dst->entities[depth].length = src->entities[depth].length;
            dst->entities[depth].buffer = 
                corto_alloc(dst->entities[depth].length * sizeof(corto_entityPerParent));

            for (sp = 0; sp < src->entities[depth].length; sp++) {
                corto_entityPerParent *srcSubParent = &src->entities[depth].buffer[sp];
                corto_entityPerParent *dstSubParent = &dst->entities[depth].buffer[sp];

                dstSubParent->parent = srcSubParent->parent;
                dstSubParent->entities.length = srcSubParent->entities.length;
                dstSubParent->entities.buffer = 
                    corto_alloc(dstSubParent->entities.length * sizeof(corto_entity));

                memcpy (
                    dstSubParent->entities.buffer, 
                    srcSubParent->entities.buffer, 
                    srcSubParent->entities.length * sizeof(corto_entity));
            }
        }

        if (corto_rwmutex_unlock(&src->lock)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

corto_entityAdmin* corto_entityAdmin_get(corto_entityAdmin *this) {
    corto_entityAdmin *result = corto_tls_get(this->key);
    if (!result) {
        result = corto_calloc(sizeof(corto_entityAdmin));
        corto_tls_set(this->key, result);
    }

    if (result->changed != this->changed) {
        corto_entityAdmin_freeEntities(result);
        if (corto_entityAdmin_copyIn(this, result)) {
            goto error;
        }
        result->changed = this->changed;
    }

    return result;
error:
    return NULL;
}

corto_int16 corto_entityAdmin_getDepthFromId(char *id) {
    corto_int16 result = 0;
    if (id) {
        char *ptr = id;
        while ((ptr = strchr(ptr + 1, '/'))) {
            result ++;
        }
    }
    return result;
}

int corto_entityAdmin_walk(corto_entityAdmin *this, corto_entityWalkAction action, char *parent, bool recursive, void *userData) {
    int result = 1;
    int depthStart = 0;
    int depthStop = CORTO_MAX_SCOPE_DEPTH;
    int parentLength = 0;
    if (parent) {
         parentLength = strlen(parent);
        if (!recursive) {
            parentLength ++; /* Match null terminator */
        }
    }

    if (this->count) {
        corto_entityAdmin *admin = corto_entityAdmin_get(this);
        if (!admin) {
            corto_seterr("failed to obtain entity admin");
            return 0;
        }

        if (parent) {
            int depth = corto_entityAdmin_getDepthFromId(parent);
            depthStart = depth;
            if (!recursive) {
                depthStop = depth + 1;
            }
        }

        int d, sp, s;
        for (d = depthStart; d < depthStop; d++) {
            for (sp = 0; sp < admin->entities[d].length; sp++) {
                corto_entityPerParent *entityPerParent = &admin->entities[d].buffer[sp];
                if (!entityPerParent->parent) {
                    if (parent) {
                        continue;
                    }
                } else {
                    if (parent && strnicmp(entityPerParent->parent, parentLength, parent)) {
                        continue;
                    }
                }
                for (s = 0; s < entityPerParent->entities.length; s ++) {
                    corto_entity *entity = &entityPerParent->entities.buffer[s];
                    if (!(result = action(entity->e, entity->instance, userData))) {
                        break;
                    }
                }
            }
            if (!result) {
                break;
            }
        }
    }

    return result;
}

int16_t corto_entityAdmin_add(
    corto_entityAdmin *this, 
    char *parent, 
    corto_object e, 
    corto_object instance) 
{
    if (!parent || !parent[0]) {
        parent = "/";
    }
    
    corto_int16 depth = corto_entityAdmin_getDepthFromId(parent);

    if (corto_rwmutex_write(&this->lock)) {
        goto error;
    }

    /* First, find an existing subscription sequence for parent of subscriber */
    corto_uint32 sp;
    corto_entityPerParent *entitiesPerParent = NULL;
    for (sp = 0; sp < this->entities[depth].length; sp++) {
        entitiesPerParent = &this->entities[depth].buffer[sp];
        if ((!parent && !entitiesPerParent->parent) || 
            (parent && entitiesPerParent->parent && !stricmp(parent, entitiesPerParent->parent))) 
        {
            break;
        } else {
            entitiesPerParent = NULL;
        }
    }

    /* If no entity sequence is found for parent, create one */
    if (!entitiesPerParent) {
        corto_uint32 length = this->entities[depth].length + 1;
        this->entities[depth].buffer =
          corto_realloc(this->entities[depth].buffer, length * sizeof(corto_entityPerParent));

        if (parent[0] != '/') {
            this->entities[depth].buffer[length - 1].parent = corto_asprintf("/%s", parent);
        } else {
            this->entities[depth].buffer[length - 1].parent = strdup(parent);
        }
                
        this->entities[depth].buffer[length - 1].entities.length = 0;
        this->entities[depth].buffer[length - 1].entities.buffer = NULL;
        this->entities[depth].length ++;
        entitiesPerParent = &this->entities[depth].buffer[length - 1];
    }

    corto_entitySeq *seq = &entitiesPerParent->entities;

    /* Add subscriber to subscription sequence */
    corto_uint32 length = seq->length + 1;
    seq->buffer = corto_realloc(seq->buffer, length * sizeof(corto_entity));
    seq->buffer[length - 1].e = e;
    seq->buffer[length - 1].instance = instance;
    seq->length ++;
    this->count ++;
    this->changed ++;

    if (corto_rwmutex_unlock(&this->lock)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

int corto_entityAdmin_remove(
    corto_entityAdmin *this, 
    char *parent,
    corto_object e,
    corto_object instance, 
    corto_bool removeAll) 
{
    corto_int32 count = 0;
    corto_int16 depth = corto_entityAdmin_getDepthFromId(parent);

    if (corto_rwmutex_write(&this->lock)) {
        goto error;
    }

    /* Find subscriber */
    corto_uint32 s, sp;
    for (sp = 0; sp < this->entities[depth].length; sp++) {
        corto_entityPerParent *entitiesPerParent = &this->entities[depth].buffer[sp];
        corto_entitySeq *seq = &entitiesPerParent->entities;
        for (s = 0; s < seq->length; s ++) {
            corto_entity *sub = &seq->buffer[s];
            if ((sub->e == e) && (removeAll || (sub->instance == instance))) {
                if (s == (seq->length - 1)) {
                    seq->buffer[s].e = NULL;
                    seq->buffer[s].instance = NULL;
                } else {
                    seq->buffer[s].e = seq->buffer[seq->length - 1].e;
                    seq->buffer[s].instance = seq->buffer[seq->length - 1].instance;

                    /* If removing all, make sure not to skip elements */
                    if (removeAll && (s == (seq->length - 2))) {
                        s --;
                    }
                }

                seq->length --;
                this->count --;
                count ++;
                if (!removeAll) {
                    break;
                }
            }
        }
    }
    if (!count && !removeAll) {
        corto_seterr(
          "unsubscribe failed, could not find entity for instance <%p>", instance);
        goto error;
    }

    if (count) {
        this->changed ++;
    }

    if (corto_rwmutex_unlock(&this->lock)) {
        goto error;
    }

    return count;
error:
    corto_rwmutex_unlock(&this->lock);
    return -1;
}
