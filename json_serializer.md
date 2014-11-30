# JSON serializer documentation

Working draft

Author: Johnny Lee (jleeothon@outlook.com)

# Usage

Provide a `db_json_ser_t` that follows the signature in json.h. Users can provide a `buffer` to which the JSON string should be serialized. When setting the buffer, `length` should be set to the length of the buffer (including `\0`). When `buffer` is left to NULL, the serializer will dynamically allocate enough memory to accomodate for the full JSON string. With `maxlength` a user can restrict the maximum length/memory allocated of the result string.

`ptr` is for internal use and points to the location where the serializer should append the next string. `itemCount` is also for internal use and determines whether insertion of a `,` is required.

`serializeMeta`, `serializeValue`, and `serializeScope` determine whether or not each of those will be serialized into the resulting JSON object.

```C
/* json.h */
typedef struct db_json_ser_t {
    db_string buffer;
    db_string ptr;
    unsigned int length;
    unsigned int maxlength;
    unsigned int itemCount;
    db_bool serializeMeta;
    db_bool serializeValue;
    db_bool serializeScope;
} db_json_ser_t;
```

Example usage:

```C
/* test json serializer.c */
struct db_serializer_s serializer = 
        db_json_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);
db_json_ser_t userData = {NULL, NULL, 0, 0, 0, TRUE, TRUE, TRUE};
db_serialize(&serializer, tc_jsonser_p_o, &userData);
```

# Serialization specification

Depending on what the serializer is told to serialize, a top-level JSON object will be returned with none or more of the following keys: `"meta"`, `"value"`, `"scope"`.

E.g. if the value and meta are requested but not the scope:

```Hyve
// tc_jsonser.hyve
object tc_jsonser::

    class Point::
        x, y: uint32;

    Point p: 10, 20::
        Point a: 34, 55;
        Point b: 6, 7;
        Point c: 8, 9;
        Point d: 1, 2;
```

```json
{
    "value": {"x": 10,"y": 20},
    "meta": {
        "name":   "p",
        "type":    "::tc_jsonser::Point",
        "parent": "::tc_jsonser",
        "childCount": 4
    }
}

```

**Warning**: the serializer doesn't insert any whitespace; spaces and line jumps are added here for readability.

**Warning**: you could indeed receive an empty top-level object if requested.

## Serialization of the value

### Primitive kinds

Serialization of primitive types is simple. The following table defines the relationship between Hyve primitive values and their corresponding JSON serialization.

| Hyve value | JSON value
-------------|-----------
| `binary` | string of uppercase Hex numbers separated by a space e.g. `A87C 4948 E9F7`
| `bitmask` | string of or'd values e.g. `gluten_free|peanut_free|lactose_free`
| `bool` | `true` or `false`
| `character` e.g. `'c'` | string with the corresponding character e.g. `"c"`
| `enum` e.g. `Color c = green;` | string of the name of the enum singleton e.g. `"green"`
| Integer and float values (e.g. `int16`, `uint32`, `float32`, `float64`) | JSON numbers
| `null` |  `null`
| `string` | JSON strings

**TODO. What are there indications regarding Unicode characters? What is going to be of Unicode with Hyve? JSON does support Unicode, only needing to escape certain sequences. How does Hyve handle them?**

For example, the following Hyve object

```Hyve
uint64 numberOfStars: 42; // the rest is an illusion
```

will be serialized into this JSON (only value)

```json
{
    "value":42
}
```

### Composite kinds

The members are serialized as a JSON object where the key is the name of the member and the value depends on its `kind`. The following example is a simplified version of an example above.

```Hyve
// tc_jsonser.hyve
object tc_jsonser::

    class Point::
        x, y: uint32;

    Point p: 10, 20;
```

```json
{
    "value": {"x": 10, "y": 20},
}
```


**TODO** how do we address a case with a anonymous object like:

```
object tc_jsonser::

    class Point2D::
        x, y: int32;

    class Point3D::
        xy: Point;
        z: int32;

    Point3D pp: 1, 2, Point{5, 6};
```

The following is the view in dbshell

```
$ pp
name:         ::tc_jsonser::pp
type:         ::tc_jsonser::PointPoint
address:      <0x90fe0d4>
refcount:     1
state:        V|DCL|DEF
attributes:   S|W |O 
parent:       ::tc_jsonser
value:        {x=1,y=2,other=<1>::tc_jsonser::Point{x=5,y=6}}
```


### Collection types



## Serialization of the scope

** TODO add scope serialization options to `db_json_ser_t`: (1) serializeScopeMeta (2) serializeValue **

The scope is serialized as a JSON object where the key is the name of the object in the scope. The value will depend on the scope serialization options.


```Hyve
void MyNamespace::
    int16 a: 9;
    int32 b: 9;
```

```JSON
{
    "scope": {
        "a": {},
        "b": {}
    }
}
```

The `serializeScopeMeta` and `serializeScopeValue` will work similarly as specified for the top-level object to be serialized. Scope of the scope cannot be serialized in a single serialization but must be manually requested.
