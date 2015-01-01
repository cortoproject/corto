/*
 * ser_xml_reader.h
 *
 *  Created on: Oct 25, 2011
 *      Author: sander
 */

#ifndef DB_XMLREADER_H_
#define DB_XMLREADER_H_

typedef struct cx_xmlreader_s* cx_xmlreader;
typedef void* cx_xmlnode;
typedef int (*cx_xmlreaderWalkCallback)(cx_xmlnode node, void* udata);
typedef int (*cx_xmlreaderWalkAttrCallback)(cx_string attr, cx_string ns, cx_string content, void* udata);

/* Open xml memory */
cx_xmlreader cx_xmlMemoryReaderNew(const char* str, const char* rootElement);

/* Open xml file */
cx_xmlreader cx_xmlreaderNew(const char* file, const char* rootElement);

/* Close xml file */
void cx_xmlreaderFree(cx_xmlreader reader);

/* Get name of node */
const char* cx_xmlnodeName(cx_xmlnode node);

/* Get namespace of node */
const char* cx_xmlnodeNs(cx_xmlnode node);

/* Get linenumber of node */
short int cx_xmlnodeLine(cx_xmlnode node);

/* Get content of node */
char* cx_xmlnodeContent(cx_xmlnode node);

/* Get parent of node */
cx_xmlnode cx_xmlnodeParent(cx_xmlnode node);

/* Get root of doc */
cx_xmlnode cx_xmlreaderRoot(cx_xmlreader reader);

/* Find element in node */
cx_xmlnode cx_xmlnodeFind(cx_xmlnode cnode, const char* element);

/* Load char */
int cx_xmlnodeAttrChar(cx_xmlnode cnode, const char* attribute, char* out);

/* Load int */
int cx_xmlnodeInt(cx_xmlnode cnode, int* out);

/* Load unsigned int */
int cx_xmlnodeUint(cx_xmlnode cnode, unsigned int* out);

/* Load float */
float cx_xmlnodeFloat(cx_xmlnode cnode, float* out);

/* Load boolean */
int cx_xmlnodeBool(cx_xmlnode cnode, unsigned int* out);

/* Load string */
char* cx_xmlnodeStr(cx_xmlnode cnode);

/* Load int from attribute */
int cx_xmlnodeAttrInt(cx_xmlnode cnode, const char* attribute, int* out);

/* Load unsigned int from attribute */
int cx_xmlnodeAttrUint(cx_xmlnode cnode, const char* attribute, unsigned int* out);

/* Load float from attribute */
float cx_xmlnodeAttrFloat(cx_xmlnode cnode, const char* attribute, float* out);

/* Load boolean from attribute */
int cx_xmlnodeAttrBool(cx_xmlnode cnode, const char* attribute, unsigned int* out);

/* Load string from attribute */
char* cx_xmlnodeAttrStr(cx_xmlnode cnode, const char* attribute);

/* Test for attribute */
int cx_xmlnodeAttrTest(cx_xmlnode cnode, const char* attribute);

/* Walk children */
int cx_xmlnodeWalkChildren(cx_xmlnode cnode, cx_xmlreaderWalkCallback callback, void* userData);

/* Walk attributes */
int cx_xmlnodeWalkAttr(cx_xmlnode cnode, cx_xmlreaderWalkAttrCallback callback, void* userData);

/* Walk xml */
int cx_xmlnodeWalk(cx_xmlnode cnode, cx_xmlreaderWalkCallback callback, void* userData);

/* Count children of node */
int cx_xmlnodehildrenCount(cx_xmlnode cnode);

/* Get child */
cx_xmlnode cx_xmlnodeGetChild(cx_xmlnode cnode, unsigned int childnode);






#endif /* SER_XML_READER_H_ */
