/*
 * ser_xml_reader.c
 *
 *  Created on: Oct 25, 2011
 *      Author: sander
 */

#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "libxml/xmlreader.h"

#include "corto_object.h"
#include "corto_err.h"
#include "xmlreader.h"

static corto_bool xml_initialized = FALSE;

typedef struct corto_xmlreader_s {
    xmlDocPtr doc;
    xmlNodePtr root;
}corto_xmlreader_s;

/* Open xml memory */
corto_xmlreader corto_xmlMemoryReaderNew(const char* str, const char* rootElement) {
    xmlDocPtr doc;
    xmlNodePtr root;
    corto_xmlreader reader;

    reader = 0;

    if (!xml_initialized) {
        xmlInitParser();
        xml_initialized = TRUE;
    }

    doc = xmlReadMemory(str, strlen(str), "noname.xml", NULL, 0);
    if (doc) {
        root = xmlDocGetRootElement(doc);
        assert(root);

        if (xmlStrcmp(root->name, (const xmlChar*)rootElement)) {
            corto_error("incorrect root element '%s' (expected '%s').", root->name, rootElement);
            xmlFreeDoc(doc);
            doc = 0;
        } else {
            reader = malloc(sizeof(corto_xmlreader_s));
            reader->doc = doc;
            reader->root = root;
        }
    }

    return reader;
}

/* Open xml file */
corto_xmlreader corto_xmlreaderNew(const char* file, const char* rootElement) {
    xmlDocPtr doc;
    xmlNodePtr root;
    corto_xmlreader reader;

    reader = 0;

    if (!xml_initialized) {
        xmlInitParser();
        xml_initialized = TRUE;
    }

    doc = xmlParseFile(file);
    if (doc) {
        root = xmlDocGetRootElement(doc);
        assert(root);

        if (xmlStrcmp(root->name, (const xmlChar*)rootElement)) {
            corto_error("incorrect root element '%s' (expected '%s').", root->name, rootElement);
            xmlFreeDoc(doc);
            doc = 0;
        } else {
            reader = malloc(sizeof(corto_xmlreader_s));
            reader->doc = doc;
            reader->root = root;
        }
    }

    return reader;
}

/* Close xml file */
void corto_xmlreaderFree(corto_xmlreader reader) {
    xmlFreeDoc(reader->doc);
    /*xmlCleanupParser();*/
    free(reader);
}

/* Get name of node */
const char* corto_xmlnodeName(corto_xmlnode cnode) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    return (const char*)node->name;
}

/* Get namespace of node */
const char* corto_xmlnodeNs(corto_xmlnode cnode) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    if (node->ns) {
        return (const char*)node->ns->prefix;
    } else {
        return 0;
    }
}

/* Get parent of node */
corto_xmlnode corto_xmlnodeParent(corto_xmlnode cnode) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    if (node->parent) {
        return (corto_xmlnode)node->parent;
    } else {
        return 0;
    }
}

/* Get linenumber of node */
short int corto_xmlnodeLine(corto_xmlnode cnode) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    return node->line;
}

/* Get content of node */
char* corto_xmlnodeContent(corto_xmlnode cnode) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    return (char*)xmlNodeGetContent(node);
}

/* Get root of doc */
corto_xmlnode corto_xmlreaderRoot(corto_xmlreader reader) {
    return (corto_xmlnode)reader->root;
}

/* Find element in node */
corto_xmlnode corto_xmlnodeFind(corto_xmlnode cnode, const char* element) {
    xmlNodePtr p;
    xmlNodePtr node = (xmlNodePtr)cnode;

    p = node->children;
    while(p) {
        if ((p->type == XML_ELEMENT_NODE) && !strcmp((char*)p->name, element)) {
            return (corto_xmlnode)p;
        }
        p = p->next;
    }
    return 0;
}

/* Load int */
int corto_xmlnodeInt(corto_xmlnode cnode, int* out) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    corto_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlNodeGetContent(node);
    if (str) {
        *out = atoi(str);
        result = 0;
    } else {
        corto_error("node '%s' has no content (expected integer).", node->name);
    }

    return result;
}

/* Load unsigned int */
int corto_xmlnodeUint(corto_xmlnode cnode, unsigned int* out) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    corto_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlNodeGetContent(node);
    if (str) {
        *out = atoi(str);
        result = 0;
    } else {
        corto_error("node '%s' has no content (expected integer).", node->name);
    }

    return result;
}

/* Load int */
float corto_xmlnodeFloat(corto_xmlnode cnode, float* out) {
    char* str;
    float result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    corto_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlNodeGetContent(node);
    if (str) {
        *out = (float)atof(str);
        result = 0;
    } else {
        corto_error("node '%s' has no content (expected float).", node->name);
    }

    return result;
}

/* Load boolean */
int corto_xmlnodeBool(corto_xmlnode cnode, unsigned int* out) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    corto_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlNodeGetContent(node);
    if (str) {
        result = 0;
        if (!strcmp("true", str) || !strcmp("TRUE", str)) {
            *out = 1;
        } else if (!strcmp("false", str) || !strcmp("FALSE", str)){
            *out = 0;
        } else {
            result = -1;
            corto_error("invalid boolean value '%s' in node '%s'.", str, node->name);
        }
        free(str);
    } else {
        corto_error("node '%s' has no content (expected integer).", node->name);
    }

    return result;
}

/* Load string */
char* corto_xmlnodeStr(corto_xmlnode cnode) {
    char* str;
    xmlNodePtr node = (xmlNodePtr)cnode;

    str = (char*)xmlNodeGetContent(node);
    if (!str) {
        corto_error("node %s has no content (expected string).", node->name);
    }

    return str;
}

/* Load char */
int corto_xmlnodeAttrChar(corto_xmlnode cnode, const char* attribute, char* out) {
    char* str;
    char result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    corto_assert(out != 0, "Invalid out parameter.", "corto_xmlnodeAttrChar: Invalid out parameter.");

    result = -1;

    str = (char*)xmlGetProp(node, (xmlChar*)attribute);
    if (str) {
        *out = *str;
        free(str);
        result = 0;
    } else {
        corto_error("char attribute '%s' not found in node '%s'.", attribute, node->name);
    }

    return result;
}

/* Load int from attribute */
int corto_xmlnodeAttrInt(corto_xmlnode cnode, const char* attribute, int* out) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    corto_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlGetProp(node, (xmlChar*)attribute);
    if (str) {
        *out = atoi(str);
        free(str);
        result = 0;
    } else {
        corto_error("integer attribute '%s' not found in node '%s'.", attribute, node->name);
    }

    return result;
}

/* Load unsigned int from attribute */
int corto_xmlnodeAttrUint(corto_xmlnode cnode, const char* attribute, unsigned int* out) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    corto_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlGetProp(node, (xmlChar*)attribute);
    if (str) {
        *out = atoi(str);
        free(str);
        result = 0;
    } else {
        corto_error("integer attribute '%s' not found in node '%s'.", attribute, node->name);
    }

    return result;
}

/* Load float from attribute */
float corto_xmlnodeAttrFloat(corto_xmlnode cnode, const char* attribute, float* out) {
    char* str;
    float result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    corto_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlGetProp(node, (xmlChar*)attribute);
    if (str) {
        *out = (float)atof(str);
        free(str);
        result = 0;
    } else {
        corto_error("float attribute '%s' not found in node '%s'.", attribute, node->name);
    }

    return result;
}
/* Load boolean from attribute */
int corto_xmlnodeAttrBool(corto_xmlnode cnode, const char* attribute, unsigned int* out) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    corto_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlGetProp(node, (xmlChar*)attribute);
    if (str) {
        result = 0;
        if (!strcmp("true", str) || !strcmp("TRUE", str) || !strcmp("True", str)) {
            *out = 1;
        } else if (!strcmp("false", str) || !strcmp("FALSE", str) || !strcmp("False", str)) {
            *out = 0;
        } else {
            result = -1;
            corto_error("invalid boolean value '%s' in attribute '%s' of node '%s'.", str, attribute, node->name);
        }
        free(str);
    } else {
        corto_error("boolean attribute '%s' not found in node '%s'.", attribute, node->name);
    }

    return result;
}

/* Load string from attribute */
char* corto_xmlnodeAttrStr(corto_xmlnode cnode, const char* attribute) {
    char* str;
    xmlNodePtr node = (xmlNodePtr)cnode;

    str = (char*)xmlGetProp(node, (xmlChar*)attribute);
    if (!str) {
        corto_error("string attribute '%s' not found in node '%s'.", attribute, node->name);
    }

    return str;
}

/* Test for attribute */
int corto_xmlnodeAttrTest(corto_xmlnode cnode, const char* attribute) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    result = 0;
    str = (char*)xmlGetProp(node, (xmlChar*)attribute);
    if (str) {
        result = 1;
        free(str);
    }

    return result;
}

/* Walk attributes */
int corto_xmlnodeWalkAttr(corto_xmlnode cnode, corto_xmlreaderWalkAttrCallback callback, void* userData) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    xmlAttrPtr attr;
    int result;

    result = 1;

    /* Walk attributes on node */
    if (node->properties) {
        attr = node->properties;

        while(result && attr) {
            result = callback((corto_string)attr->ns, (corto_string)attr->name, (corto_string)attr->children->content, userData);
            attr = attr->next;
        }
    }

    return result;
}

/* Walk children */
int corto_xmlnodeWalkChildren(corto_xmlnode cnode, corto_xmlreaderWalkCallback callback, void* userData) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    return corto_xmlnodeWalk(node->xmlChildrenNode, callback, userData);
}

/* Walk xml */
int corto_xmlnodeWalk(corto_xmlnode cnode, corto_xmlreaderWalkCallback callback, void* userData) {
    int result = 1;
    xmlNodePtr node = (xmlNodePtr)cnode;

    while(node) {
        if (node->type == XML_ELEMENT_NODE) {
            if (!(result = callback(node, userData))) {
                break;
            }
        }
        node = node->next;
    }

    return result;
}

/* Count children of node */
int corto_xmlnodeChildrenCount(corto_xmlnode cnode) {
    int n = 0;
    xmlNodePtr child;
    xmlNodePtr node = (xmlNodePtr)cnode;

    child = node->children;
    while(child) {
        if (child->type == XML_ELEMENT_NODE) {
            n++;
        }
        child = child->next;
    }

    return n;
}

corto_xmlnode corto_xmlnodeGetChild(corto_xmlnode cnode, unsigned int childnode) {
    unsigned int n = 0;
    xmlNodePtr child;
    xmlNodePtr node = (xmlNodePtr)cnode;

    child = node->children;
    while(child) {
        if (child->type == XML_ELEMENT_NODE) {
            if (n == childnode) {
                return (corto_xmlnode)child;
            }
            n++;
        }
        child = child->next;
    }
    return 0;
}



