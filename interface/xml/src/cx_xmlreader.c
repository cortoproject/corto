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

#include "cx_object.h"
#include "cx_err.h"
#include "cx_xmlreader.h"

static cx_bool xml_initialized = FALSE;

typedef struct cx_xmlreader_s {
    xmlDocPtr doc;
    xmlNodePtr root;
}cx_xmlreader_s;

/* Open xml memory */
cx_xmlreader cx_xmlMemoryReaderNew(const char* str, const char* rootElement) {
    xmlDocPtr doc;
    xmlNodePtr root;
    cx_xmlreader reader;

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
            cx_error("incorrect root element '%s' (expected '%s').", root->name, rootElement);
            xmlFreeDoc(doc);
            doc = 0;
        } else {
            reader = malloc(sizeof(cx_xmlreader_s));
            reader->doc = doc;
            reader->root = root;
        }
    }

    return reader;
}

/* Open xml file */
cx_xmlreader cx_xmlreaderNew(const char* file, const char* rootElement) {
    xmlDocPtr doc;
    xmlNodePtr root;
    cx_xmlreader reader;

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
            cx_error("incorrect root element '%s' (expected '%s').", root->name, rootElement);
            xmlFreeDoc(doc);
            doc = 0;
        } else {
            reader = malloc(sizeof(cx_xmlreader_s));
            reader->doc = doc;
            reader->root = root;
        }
    }

    return reader;
}

/* Close xml file */
void cx_xmlreaderFree(cx_xmlreader reader) {
    xmlFreeDoc(reader->doc);
    /*xmlCleanupParser();*/
    free(reader);
}

/* Get name of node */
const char* cx_xmlnodeName(cx_xmlnode cnode) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    return (const char*)node->name;
}

/* Get namespace of node */
const char* cx_xmlnodeNs(cx_xmlnode cnode) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    if (node->ns) {
        return (const char*)node->ns->prefix;
    } else {
        return 0;
    }
}

/* Get parent of node */
cx_xmlnode cx_xmlnodeParent(cx_xmlnode cnode) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    if (node->parent) {
        return (cx_xmlnode)node->parent;
    } else {
        return 0;
    }
}

/* Get linenumber of node */
short int cx_xmlnodeLine(cx_xmlnode cnode) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    return node->line;
}

/* Get content of node */
char* cx_xmlnodeContent(cx_xmlnode cnode) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    return (char*)xmlNodeGetContent(node);
}

/* Get root of doc */
cx_xmlnode cx_xmlreaderRoot(cx_xmlreader reader) {
    return (cx_xmlnode)reader->root;
}

/* Find element in node */
cx_xmlnode cx_xmlnodeFind(cx_xmlnode cnode, const char* element) {
    xmlNodePtr p;
    xmlNodePtr node = (xmlNodePtr)cnode;

    p = node->children;
    while(p) {
        if ((p->type == XML_ELEMENT_NODE) && !strcmp((char*)p->name, element)) {
            return (cx_xmlnode)p;
        }
        p = p->next;
    }
    return 0;
}

/* Load int */
int cx_xmlnodeInt(cx_xmlnode cnode, int* out) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    cx_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlNodeGetContent(node);
    if (str) {
        *out = atoi(str);
        result = 0;
    } else {
        cx_error("node '%s' has no content (expected integer).", node->name);
    }

    return result;
}

/* Load unsigned int */
int cx_xmlnodeUint(cx_xmlnode cnode, unsigned int* out) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    cx_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlNodeGetContent(node);
    if (str) {
        *out = atoi(str);
        result = 0;
    } else {
        cx_error("node '%s' has no content (expected integer).", node->name);
    }

    return result;
}

/* Load int */
float cx_xmlnodeFloat(cx_xmlnode cnode, float* out) {
    char* str;
    float result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    cx_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlNodeGetContent(node);
    if (str) {
        *out = (float)atof(str);
        result = 0;
    } else {
        cx_error("node '%s' has no content (expected float).", node->name);
    }

    return result;
}

/* Load boolean */
int cx_xmlnodeBool(cx_xmlnode cnode, unsigned int* out) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    cx_assert(out != 0, "Invalid out parameter.");

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
            cx_error("invalid boolean value '%s' in node '%s'.", str, node->name);
        }
        free(str);
    } else {
        cx_error("node '%s' has no content (expected integer).", node->name);
    }

    return result;
}

/* Load string */
char* cx_xmlnodeStr(cx_xmlnode cnode) {
    char* str;
    xmlNodePtr node = (xmlNodePtr)cnode;

    str = (char*)xmlNodeGetContent(node);
    if (!str) {
        cx_error("node %s has no content (expected string).", node->name);
    }

    return str;
}

/* Load char */
int cx_xmlnodeAttrChar(cx_xmlnode cnode, const char* attribute, char* out) {
    char* str;
    char result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    cx_assert(out != 0, "Invalid out parameter.", "cx_xmlnodeAttrChar: Invalid out parameter.");

    result = -1;

    str = (char*)xmlGetProp(node, (xmlChar*)attribute);
    if (str) {
        *out = *str;
        free(str);
        result = 0;
    } else {
        cx_error("char attribute '%s' not found in node '%s'.", attribute, node->name);
    }

    return result;
}

/* Load int from attribute */
int cx_xmlnodeAttrInt(cx_xmlnode cnode, const char* attribute, int* out) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    cx_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlGetProp(node, (xmlChar*)attribute);
    if (str) {
        *out = atoi(str);
        free(str);
        result = 0;
    } else {
        cx_error("integer attribute '%s' not found in node '%s'.", attribute, node->name);
    }

    return result;
}

/* Load unsigned int from attribute */
int cx_xmlnodeAttrUint(cx_xmlnode cnode, const char* attribute, unsigned int* out) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    cx_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlGetProp(node, (xmlChar*)attribute);
    if (str) {
        *out = atoi(str);
        free(str);
        result = 0;
    } else {
        cx_error("integer attribute '%s' not found in node '%s'.", attribute, node->name);
    }

    return result;
}

/* Load float from attribute */
float cx_xmlnodeAttrFloat(cx_xmlnode cnode, const char* attribute, float* out) {
    char* str;
    float result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    cx_assert(out != 0, "Invalid out parameter.");

    result = -1;

    str = (char*)xmlGetProp(node, (xmlChar*)attribute);
    if (str) {
        *out = (float)atof(str);
        free(str);
        result = 0;
    } else {
        cx_error("float attribute '%s' not found in node '%s'.", attribute, node->name);
    }

    return result;
}
/* Load boolean from attribute */
int cx_xmlnodeAttrBool(cx_xmlnode cnode, const char* attribute, unsigned int* out) {
    char* str;
    int result;
    xmlNodePtr node = (xmlNodePtr)cnode;

    cx_assert(out != 0, "Invalid out parameter.");

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
            cx_error("invalid boolean value '%s' in attribute '%s' of node '%s'.", str, attribute, node->name);
        }
        free(str);
    } else {
        cx_error("boolean attribute '%s' not found in node '%s'.", attribute, node->name);
    }

    return result;
}

/* Load string from attribute */
char* cx_xmlnodeAttrStr(cx_xmlnode cnode, const char* attribute) {
    char* str;
    xmlNodePtr node = (xmlNodePtr)cnode;

    str = (char*)xmlGetProp(node, (xmlChar*)attribute);
    if (!str) {
        cx_error("string attribute '%s' not found in node '%s'.", attribute, node->name);
    }

    return str;
}

/* Test for attribute */
int cx_xmlnodeAttrTest(cx_xmlnode cnode, const char* attribute) {
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
int cx_xmlnodeWalkAttr(cx_xmlnode cnode, cx_xmlreaderWalkAttrCallback callback, void* userData) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    xmlAttrPtr attr;
    int result;

    result = 1;

    /* Walk attributes on node */
    if (node->properties) {
        attr = node->properties;

        while(result && attr) {
            result = callback((cx_string)attr->ns, (cx_string)attr->name, (cx_string)attr->children->content, userData);
            attr = attr->next;
        }
    }

    return result;
}

/* Walk children */
int cx_xmlnodeWalkChildren(cx_xmlnode cnode, cx_xmlreaderWalkCallback callback, void* userData) {
    xmlNodePtr node = (xmlNodePtr)cnode;
    return cx_xmlnodeWalk(node->xmlChildrenNode, callback, userData);
}

/* Walk xml */
int cx_xmlnodeWalk(cx_xmlnode cnode, cx_xmlreaderWalkCallback callback, void* userData) {
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
int cx_xmlnodeChildrenCount(cx_xmlnode cnode) {
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

cx_xmlnode cx_xmlnodeGetChild(cx_xmlnode cnode, unsigned int childnode) {
    unsigned int n = 0;
    xmlNodePtr child;
    xmlNodePtr node = (xmlNodePtr)cnode;

    child = node->children;
    while(child) {
        if (child->type == XML_ELEMENT_NODE) {
            if (n == childnode) {
                return (cx_xmlnode)child;
            }
            n++;
        }
        child = child->next;
    }
    return 0;
}



