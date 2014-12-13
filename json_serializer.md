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
/* test_json_serializer.c */
struct db_serializer_s serializer = 
        db_json_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);
db_json_ser_t userData = {NULL, NULL, 0, 0, 0, TRUE, TRUE, TRUE};
db_serialize(&serializer, tc_jsonser_p_o, &userData);
```

# Serialization specification

Depending on what the serializer is told to serialize, a top-level JSON object will be returned with none or more of the following keys: `"meta"`, `"value"`, `"scope"`.

E.g. if the value and meta are requested but not the scope:

```Hyve
void example::

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
        "type":    "::example::Point",
        "parent": "::example",
        "childCount": 4
    }
}

```

**Warning**: the serializer doesn't insert any whitespace; spaces and line jumps are added here for readability.

**Warning**: you could indeed receive an empty top-level object if requested.

## Serialization of the value

### Primitive kinds

Serialization of primitive types is simple. The following table defines the relationship between Hyve primitive values and their corresponding JSON serialization. Some have embedded annotation for their types.

| Hyve value | JSON value
-------------|-----------
| `binary` | A string starting with "@B" and followed by a uppercase Hex numbers separated by a space e.g. `@B A87C 4948 E9F7`
| `bitmask` | A string starting with "@M" and followed by or'd values e.g. `@M gluten_free|peanut_free|lactose_free`
| `bool` | `true` or `false`
| `character` e.g. `'c'` | string with the corresponding character e.g. `"c"`
| `enum` e.g. `Color c = green;` | A string starting with "@E" and followed by the name of the enum singleton e.g. `"@E green"`
| Integer and float values (e.g. `int16`, `uint32`, `float32`, `float64`) | JSON numbers
| `null` |  `null`
| `string` | JSON strings

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

### Composite kinds and reference members

The members are serialized as a JSON object where the key is the name of the member and the value depends on its `kind`. The following example is a simplified version of an example above.

Members of primitive types are serialized just as specified [above](#primitive-kinds). For example, in the following source Hyve script, the object `void::example::p`:

```Hyve
void example::

    class Point::
        x, y: uint32;

    Point p: 10, 20;
```

is serialized (only value) into this JSON:

```json
{
    "value": {"x": 10, "y": 20},
}
```

Members of reference types (e.g. instances of a class) are annotated with "@R" followed by the fully scoped name of the object.

| Hyve value | JSON value
|------------|-----------
| reference e.g. `::example::myobject` | `"@R ::example::myobject"`

For `example::mydog` in the following Hyve script:
 
```Hyve
void example::
    
    class DogFood:
        uint32 calories;
    
    class Dog:
        favoriteFood: DogFood;
    
    DogFood dietDogFood: 0;
    
    Dog mydog: dietDogFood;
```

is serialized as:

```json
{
    "value": {
        "favoriteFood": "@R ::example::dietDogFood"
    }
}
```

### Disambiguation of strings

In summary, these annotations can appear:

| Annotation | Kind
|------------|------
| @B         | `binary`
| @M         | `bitmask`
| @E         | `enum`
| @R         | reference

Hyve strings that start with the annotation character (@) will always be escaped regardless of whether or not we can run into disambiguation with the above types.

Example:

| Hyve string   | JSON string
|---------------|------------
| `"hello"`     | `"hello"`
| `"@E"`        | `"@@E"`
| `"@E a"`      | `"@@E a"`
| `"@@E"`       | `"@@@E"`
| `"@hey"`      | `"@@hey"`

Some backwards inferences:

| JSON string | Hyve value
|-------------|-----------
| `@E a`      | `enum` with the value `a`
| `@E`        | not valid

### Collection kinds

`array`, `sequence`, and `list` types are serialized as JSON arrays. The items within the lists are serialized according to the rules for [primitives](#primitive-kinds) or [references](#composite-kinds-and-reference-members).

For example, in the following Hyve script:

```hyve
void example::
    list{string} greetings: "hello", "hallo", "hola", "konnichiwa";
```

the object `::example::greetings` will be serialized as:

```json
{
    "value": ["hello", "hallo", "hola", "konnichiwa"]
}
```

**TODO the following specificatino is not JSON-compliant**

`map` kinds are serialized similar to composite types, that is, a JSON object, but they key and values of the JSON object follow appropriate serialization rules for the kinds of the keys and values of the Hyve map.

For example, in the following Hyve script:

```Hyve
void example::
    map{int16, string} hakkaNumbers: 1: "yit", 2: "gni", 3:"sam";
```

the object `::example::hakkaNumbers` is serialized as:

```json
{
    "value": {1:"yit", 2:"gni", 3:"sam"}
}
```

**END TODO**

### Additional notes

Objects of type `void` cannot generate a `"value"` key. The serializer will fail silently.

## Serialization of the scope

The scope of an object is serialized as a JSON array of JSON objects describing the metadata of each.

For ``::example`` in the this Hyve script:

```Hyve
void example::
    int16 a: 9;
    string b: "10";
```

the following JSON is generated (meta and scope, value cannot be generated for `void`):

```json
{
    "meta": {
        "name":         "::example",
        "type":         "::hyve::lang::void",
        "state":        "V|DCL|DEF",
        "attributes":   "S|O",
        "parent":       "::",
        "childCount":   "2"
    },
    "scope": [
        {
            "name":         "::example::a",
            "type":         "::hyve::lang::int16",
            "state":        "V|DCL|DEF",
            "attributes":   "S|W |O ",
            "parent":       "::example"
        },
        {
            "name":         "::example::b",
            "type":         "::hyve::lang::string",
            "state":        "V|DCL|DEF",
            "attributes":   "S|W |O ",
            "parent":       "::example"
        }
    ]
}
```

## Pending issues

### Describing anonymous objects

```
object tc_jsonser::

    class Point2D::
        x, y: int32;

    class Point3D::
        xy: Point;
        z: int32;

    Point3D pp: 1, 2, Point{5, 6};
```

The following is the view in `dbsh`

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

### Specification of maps

Described above.
