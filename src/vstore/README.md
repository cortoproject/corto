# The Virtual Store
This is the source code of the virtual object store, which is compiled into
the corto runtime. The virtual store is an abstraction on top of other sources
of data (like databases, files, web services, protocols). The store is called
"virtual" because it does not actually store anything. Data is retrieved and
saved from and to the original storage as an application needs it.

The virtual store is designed to mimic the real world. It therefore organizes 
data in a hierarchy, because hierarchies are how typically the world is broken 
down (yes, graphs are supported too). The first job of an application is to
define what the virtual store looks like. The result is a hierarchical scaffold
which acts as a supporting structure for any data that is connected to it.

The virtual store can be inspected with a query language that can both be ran as
single-shot and in realtime. These queries are translated to *mounts*,
which are the entities that connect other datasources to the virtual store (more
on that later). The query language is specifically optimized for hierarchically
structured data:

## Files
An overview of the files, and what they do:

| file | description |
|------|-------------|
| dispatcher.c | Interface for catching and queueing events for asynchronous processing |
| event.c | Base event class |
| frame.c | Type that expresses a beginning or end of a time window |
| idmatch.c | Expression format extended from fnmatch designed to match identifiers |
| invokeEvent.c | Event that communicates a method call to a mount |
| loader.c | Mount that loads packages into the virtual store |
| mount.c | Implementation of the mount class (see below) |
| observer.c | Observe notifications from the object store |
| observerEvent.c | Event used to communicate notifications to an observer |
| package.c | Base class for packages |
| query.c | The query class, used to capture information in a query |
| result.c | The result class, used to communicate objects from the virtual store |
| route.c | The route class, used in a router (see below) |
| router.c | The router class, used to route requests to different callbacks |
| routerimpl.c | Default implementation of router |
| select.c | The corto_select function, which performs single shot queries |
| subscriber.c | The corto_subscriber class, which performs realtime queries |
| subscriberEvent.c | Event used to communicate notifications to a subscriber |

You may remark that some files do not necessarily seem part of the virtual store. 
That is correct. A few classes need to be moved to other locations.

## Mounts
The most important class in the implementation of the virtual store is the 
`mount`. Mounts are objects that can connect data from other sources to the
virtual store. They are called "mounts" because of their similarity to UNIX mounts,
except that:

* corto mounts mount structured data, not unstructured files
* corto mounts can provide realtime updates
* corto mounts can spawn other mounts dynamically

They are similar in that they:

* abstract away implementation details, offer a simple unified interface
* support hierarchically structured data
* can mount data anywhere, independent of their source

Frameworks other than corto have also adopted the mount abstraction as a way of
virtually exposing data through a hierarchical data layer. Most notably are the
following drafts of the IETF, which specify how data from external sources can
be mounted in a local representation:

https://tools.ietf.org/html/draft-clemm-netmod-mount-06

https://datatracker.ietf.org/doc/draft-ietf-netmod-schema-mount/

### Queries and mounts
When an application queries corto for data, the corto query engine will look for
matching mounts. It does this with a highly optimized algorithm that looks at 
which scopes the query is interested in, and matching that to the locations in 
the virtual store where mounts are mounted. For example:

If an application creates mount `A` on `/hello` and mount `B` on `/foo`, and then
runs the following single shot query:
```
select * from foo
```
then only mount `B` will be matched to the query. In practice this matching
can get much more complicated than this simple example (hierarchical queries, 
type filters, identifier expressions) but for now it serves the purpose of 
illustrating the concept.

The second thing the query engine does is, after it has collected a list of mounts
that match, transpose the query to mount-specific queries. To make it possible
for mounts to be mounted anywhere in the store without changing any code, the
query needs to be relative to the point on which a mount is mounted.

In our simple example, the query sent to mount `B` looks like this:
```
select * from .
```
where `.` is equivalent to "current scope" (similar to "current directory"). As
you can see, the query engine translated `from /foo` to `.`, because the mount 
was mounted on `/foo`. That way, the application could simply mount `B`  on 
`/bar` without changing any code.

The mount, in turn, returns the results of the query also relative to its mount
point, which are then transposed again back to the original query. In this case,
if the mount returned an object called `obj`, it would be returned as `./obj`.
This is because query results are returned relative to the `from` expression.

If the application had run this query:
```
select foo/* from /
```
the result would have been `foo/obj`.

### Query results
Queries, both realtime and single shot, format query results as a `vstore/result`
type. The members of this type describe the metadata and serialized value of an
object. That way, a user can evaluate data without having to insert objects from
the virtual store into the object store.

This example shows how to do a single shot query and iterate over its results:
```c
corto_iter it;
corto_select("*").from("/foo").iter(&it);

while (corto_iter_hasNext(&it)) {
    corto_result *r = corto_iter_next(&it);
    printf("id = %s, parent = %s, type = %s",
        r->id,
        r->parent,
        r->type);
}
```
The corto architecture is built such that an application never has to occupy more
memory than is required for a single `corto_result` while iterating over the 
results of a query. Allthough it is ultimately up to a mount to take advantage
of the capabilities of the API, the corto architecture in theory allows for 
processing infinite datasets on devices of any size.

This is the same example, but for a realtime query (using a subscriber):
```c
void callback(corto_subscriberEvent *e) {
    // e->data is of type corto_result*
    printf("id = %s, parent = %s, type = %s",
        e->data.id,
        e->data.parent,
        e->data.type);    
}

void main() {
    corto_subscriber s = corto_subscribe("*").from("/foo").callback(cb);
    // keep alive
}
```

### Content types
In addition to predicates that describe what kind of data to match, a query
can also contain information about how the data should be formatted. This can
be specified with the `contentType` function, like this:

```c
corto_select("*").from("/foo").contentType("text/json").iter(it);
```
All results returned by this query will be formatted as JSON. This allows an
application to inspect the value of an object (one object at a time) in 
serialized form, without having to go through the object store. An additional 
benefit comes when the serialized format is the same as that from the data
source, in which case corto is intelligent enough to just pass through the
serialized data.

Specifiying a contentType also works for subscribers:
```c
corto_subscribe("*").from("/foo").contentType("text/json").callback(cb);
```

The serialized value can be obtained like this (assuming `r` is the `corto_result`):
```c
printf("value = %s\n", corto_result_getText(r));
```

or for subscribers:
```c
printf("value = %s\n", corto_result_getText(&e->data));
```

### Implement a mount
A mount can be as simple or as complex as you want. The simplest mount can be
less than 20 lines of (C) code, whereas a complex mount can be several thousands
of lines or even more. It all depends on what kind of technology the mount connects to, how
feature rich the mount has to be and how much of the interface you want to 
implement. Often the best approach is to start off simple, and progressively
layer on more complexity as it is needed.

Mounts are instances of the `corto/vstore/mount` class. This is a builtin class
with overridable methods that mount implementations can selectively override. The
most used overridable functions are `on_notify` and `on_query`. The former notifies
a mount of an event in either the virtual store or object store. The latter is
invoked when a user performs a single shot query.

In addition to `on_notify` and `on_query`, there is also `on_subscribe` and 
`on_unsubscribe` which are invoked when a subscriber is created with a query that
matches the mount. This matching uses the same logic as how a query is matched to
a set of mounts.

There are more callbacks, though these are the most important ones. Lets implement
a simple mount using the `on_notify` callback.

#### Create a custom mount class
First we have to create a definition for our own mount class. There are various
ways in which we can do this, but the simplest way is with a corto definition
file. First, create a new application project, and create a new definition file:

```
corto create MyMount
touch MyMount/MyMount.cx
```

Then, add the following lines to `MyMount.cx`:
```
in package MyMount

class CustomMount: vstore/mount:/
    void on_notify(subscriberEvent e) override
```
If you are familiar with corto definition files, you'll notice this looks just
like a regular class, just one that happens to inherit from mount. Now build the
project with:
```
corto build
```
We now have a file `MyMount/src/CustomMount.c` which contains an empty function
body for `MyMount_CustomMount_on_notify`. Assuming we have a function called
`writeData` that stores data in some kind of external storage, we can now do:
```c
void MyMount_CustomMount_on_notify(corto_subscriberEvent *e) {
    writeData(
        e->data.id,
        e->data.parent,
        e->data.type
    );
}
```
This is not massively impressive, as we are not actually writing the value of
the object, only the metadata. Suppose we want to store the value of the object
serialied to JSON, what code do we have to add to the `on_notify` method that 
serializes the object data to JSON?

##### A dirty little secret about mounts
The answer is: not much. Mounts *inherit from subscribers*. Because they
inherit from subscribers, they also inherit the capability to specify a contentType.
Lets instantiate our mount, and specify a contentType using a configuration file.
Create a file called `config.json`:
```
touch MyMount/config.json
```
In this file, add the following JSON:
```json
{
    "id": "config/MyCustomMount",
    "type": "MyMount/CustomMount",
    "value": {
        "contentType": "text/json",
        "query": {
            "from": "/foo"
        }
    }
}
```
Note the `query` member, which specifies the mount point. This is yet another
clue that the mount class actually inherits from the subscriber class. Indeed,
mounts use the subscriber query to subscribe for data in the virtual store.

Now, add this line to the main function in `MyMount/src/MyMount.c`:
```c
corto_use("config.json", 0, NULL);
```
And change the implementation of `on_notify` to this (using our fictional writeData function):
```c
    writeData(
        e->data.id,
        e->data.parent,
        e->data.type,
        corto_result_getText(&e->data) // Returns JSON!
    );
```

That was pretty easy! As you can imagine, mounts can be a lot more
complicated, but it goes beyond the scope of this document to dive into that now.
