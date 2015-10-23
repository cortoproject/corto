/*
 * ser_xml_reader.h
 *
 *  Created on: Oct 25, 2011
 *      Author: sander
 */

#ifndef CORTO_XMLREADER_H_
#define CORTO_XMLREADER_H_

typedef struct corto_xmlreader_s* corto_xmlreader;
typedef void* corto_xmlnode;
typedef int (*corto_xmlreaderWalkCallback)(corto_xmlnode node, void* udata);
typedef int (*corto_xmlreaderWalkAttrCallback)(corto_string attr, corto_string ns, corto_string content, void* udata);

/* Open xml memory */
corto_xmlreader corto_xmlMemoryReaderNew(const char* str, const char* rootElement);

/* Open xml file */
corto_xmlreader corto_xmlreaderNew(const char* file, const char* rootElement);

/* Close xml file */
void corto_xmlreaderFree(corto_xmlreader reader);

/* Get name of node */
const char* corto_xmlnodeName(corto_xmlnode node);

/* Get namespace of node */
const char* corto_xmlnodeNs(corto_xmlnode node);

/* Get linenumber of node */
short int corto_xmlnodeLine(corto_xmlnode node);

/* Get content of node */
char* corto_xmlnodeContent(corto_xmlnode node);

/* Get parent of node */
corto_xmlnode corto_xmlnodeParent(corto_xmlnode node);

/* Get root of doc */
corto_xmlnode corto_xmlreaderRoot(corto_xmlreader reader);

/* Find element in node */
corto_xmlnode corto_xmlnodeFind(corto_xmlnode cnode, const char* element);

/* Load char */
int corto_xmlnodeAttrChar(corto_xmlnode cnode, const char* attribute, char* out);

/* Load int */
int corto_xmlnodeInt(corto_xmlnode cnode, int* out);

/* Load unsigned int */
int corto_xmlnodeUint(corto_xmlnode cnode, unsigned int* out);

/* Load float */
float corto_xmlnodeFloat(corto_xmlnode cnode, float* out);

/* Load boolean */
int corto_xmlnodeBool(corto_xmlnode cnode, unsigned int* out);

/* Load string */
char* corto_xmlnodeStr(corto_xmlnode cnode);

/* Load int from attribute */
int corto_xmlnodeAttrInt(corto_xmlnode cnode, const char* attribute, int* out);

/* Load unsigned int from attribute */
int corto_xmlnodeAttrUint(corto_xmlnode cnode, const char* attribute, unsigned int* out);

/* Load float from attribute */
float corto_xmlnodeAttrFloat(corto_xmlnode cnode, const char* attribute, float* out);

/* Load boolean from attribute */
int corto_xmlnodeAttrBool(corto_xmlnode cnode, const char* attribute, unsigned int* out);

/* Load string from attribute */
char* corto_xmlnodeAttrStr(corto_xmlnode cnode, const char* attribute);

/* Test for attribute */
int corto_xmlnodeAttrTest(corto_xmlnode cnode, const char* attribute);

/* Walk children */
int corto_xmlnodeWalkChildren(corto_xmlnode cnode, corto_xmlreaderWalkCallback callback, void* userData);

/* Walk attributes */
int corto_xmlnodeWalkAttr(corto_xmlnode cnode, corto_xmlreaderWalkAttrCallback callback, void* userData);

/* Walk xml */
int corto_xmlnodeWalk(corto_xmlnode cnode, corto_xmlreaderWalkCallback callback, void* userData);

/* Count children of node */
int corto_xmlnodehildrenCount(corto_xmlnode cnode);

/* Get child */
corto_xmlnode corto_xmlnodeGetChild(corto_xmlnode cnode, unsigned int childnode);






#endif /* SER_XML_READER_H_ */
