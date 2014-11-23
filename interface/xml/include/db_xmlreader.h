/*
 * ser_xml_reader.h
 *
 *  Created on: Oct 25, 2011
 *      Author: sander
 */

#ifndef DB_XMLREADER_H_
#define DB_XMLREADER_H_

typedef struct db_xmlreader_s* db_xmlreader;
typedef void* db_xmlnode;
typedef int (*db_xmlreaderWalkCallback)(db_xmlnode node, void* udata);
typedef int (*db_xmlreaderWalkAttrCallback)(db_string attr, db_string ns, db_string content, void* udata);

/* Open xml memory */
db_xmlreader db_xmlMemoryReaderNew(const char* str, const char* rootElement);

/* Open xml file */
db_xmlreader db_xmlreaderNew(const char* file, const char* rootElement);

/* Close xml file */
void db_xmlreaderFree(db_xmlreader reader);

/* Get name of node */
const char* db_xmlnodeName(db_xmlnode node);

/* Get namespace of node */
const char* db_xmlnodeNs(db_xmlnode node);

/* Get linenumber of node */
short int db_xmlnodeLine(db_xmlnode node);

/* Get content of node */
char* db_xmlnodeContent(db_xmlnode node);

/* Get parent of node */
db_xmlnode db_xmlnodeParent(db_xmlnode node);

/* Get root of doc */
db_xmlnode db_xmlreaderRoot(db_xmlreader reader);

/* Find element in node */
db_xmlnode db_xmlnodeFind(db_xmlnode cnode, const char* element);

/* Load char */
int db_xmlnodeAttrChar(db_xmlnode cnode, const char* attribute, char* out);

/* Load int */
int db_xmlnodeInt(db_xmlnode cnode, int* out);

/* Load unsigned int */
int db_xmlnodeUint(db_xmlnode cnode, unsigned int* out);

/* Load float */
float db_xmlnodeFloat(db_xmlnode cnode, float* out);

/* Load boolean */
int db_xmlnodeBool(db_xmlnode cnode, unsigned int* out);

/* Load string */
char* db_xmlnodeStr(db_xmlnode cnode);

/* Load int from attribute */
int db_xmlnodeAttrInt(db_xmlnode cnode, const char* attribute, int* out);

/* Load unsigned int from attribute */
int db_xmlnodeAttrUint(db_xmlnode cnode, const char* attribute, unsigned int* out);

/* Load float from attribute */
float db_xmlnodeAttrFloat(db_xmlnode cnode, const char* attribute, float* out);

/* Load boolean from attribute */
int db_xmlnodeAttrBool(db_xmlnode cnode, const char* attribute, unsigned int* out);

/* Load string from attribute */
char* db_xmlnodeAttrStr(db_xmlnode cnode, const char* attribute);

/* Test for attribute */
int db_xmlnodeAttrTest(db_xmlnode cnode, const char* attribute);

/* Walk children */
int db_xmlnodeWalkChildren(db_xmlnode cnode, db_xmlreaderWalkCallback callback, void* userData);

/* Walk attributes */
int db_xmlnodeWalkAttr(db_xmlnode cnode, db_xmlreaderWalkAttrCallback callback, void* userData);

/* Walk xml */
int db_xmlnodeWalk(db_xmlnode cnode, db_xmlreaderWalkCallback callback, void* userData);

/* Count children of node */
int db_xmlnodehildrenCount(db_xmlnode cnode);

/* Get child */
db_xmlnode db_xmlnodeGetChild(db_xmlnode cnode, unsigned int childnode);






#endif /* SER_XML_READER_H_ */
