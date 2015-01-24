// Define cx object
cx = {
    object: function(parent, name) {
        this.parent = parent;
        this.name = name;
        this.scope = {};
        this.value = {};
        this.meta = {};
    },

    serializer: function(object, composite, collection, primitive, member, element) {
        this.serializeObject = object;
        this.serializeComposite = composite;
        this.serializeCollection = collection;
        this.serializePrimitive = primitive;
        this.serializeMember = member;
        this.serializeElement = element;
    },

    setMe: function(name) {
        this.me = cx.resolve(name);
    },

    // Convert reference string to a link
    toLink: function(link) {
        var p = cx.me;
        var prefix = "";
        var result = "";
        var name = "";
        while (p.parent) {
            p = p.parent;
            prefix += "../";
        }

        for (var i = 0, start = 0; i < link.length; i++) {
            var ch = link[i];
            if (ch === ':') {
                if (i === 0) {
                    result = "<a class='reference' href='" + prefix + "index.html'>::</a>";
                } else {
                    name = link.slice(start, i);
                    if (start > 2) {
                        result += "::";
                    }
                    prefix += name + "/";
                    result += "<a class='reference' href='" + prefix + "index.html'>" + name + "</a>";
                }
                i++;
                start = i + 1;
            }
        }

        name = link.slice(start, i);
        prefix += name + "/";
        if (start > 2) {
            result += "::";
        }
        result += "<a class='reference' href='" + prefix + "index.html'>" + name + "</a>";

        return result;        
    }
}

// Define cx.serializer prototype
cx.serializer.prototype = {

    serializeValue: function(o) {
        if (o instanceof Array) {
            return this.serializeCollection(this, o);
        } else if (o instanceof Object) {
            return this.serializeComposite(this, o);
        } else {
            return this.serializePrimitive(this, o);
        }
    },

    serializeMembers: function(o) {
        var result = "";
        for (var k in o) {
            if (k != '@base') {
                this.info = k;
                result += this.serializeMember(this, o[k]);
            } else {
                result += this.serializeValue(o[k]);
            }
        }
        return result;
    },

    serializeElements: function(o) {
        var result = "";
        o.forEach(function (item, i) {
            this.info = i;
            result += this.serializeElement(this, item);
        }, this);
        return result;
    },

    serialize: function(o) {
        this.info = undefined;
        if (this.serializeComposite === undefined) {
            this.serializeComposite = function(s, o) {return s.serializeMembers(o)};
        }
        if (this.serializeCollection === undefined) {
            this.serializeCollection = function(s, o) {return s.serializeElements(o)};
        }
        if (this.serializeMember === undefined) {
            this.serializeMember = function(s, o) {return s.serializeValue(o)};
        }
        if (this.serializeElement === undefined) {
            this.serializeElement = function(s, o) {return s.serializeValue(o)};
        }
        return this.serializeObject(this, o);
    }
};

// Define cx.object prototype
cx.object.prototype = {

    // Return id of object (fully scoped name)
    id: function() {
        return this.name; // TODO
    },

    // Resolve object
    resolve: function(fullname) {
        var scope = this;
        var o = undefined;
        for (var i = 0, start = 0; i < fullname.length; i++) {
            var ch = fullname[i];
            if (ch === ':') {
                if (i === 0) {
                    scope = cx.root;
                } else {
                    var name = fullname.slice(start, i);
                    scope = scope.scope[name];
                    if (scope === undefined) {
                        break;
                    }
                }
                i++;
                start = i + 1;
            }
        }

        o = scope.scope[fullname.slice(start, i)];

        if ((o === undefined) && (scope.parent !== undefined)) {
            o = scope.parent.resolve(fullname);
        }

        return o;
    },

    // Declare a new object
    declare: function(name) {
        var o = this.scope[name];
        if (o == undefined) {
            var o = new cx.object(this, name);
            this.scope[name] = o;
        }
        return o;
    },

    // Convert metadata to HTML
    metaToHtml: function() {
        function parseStates(states) {
            var buffer = "";
            buffer = states.replace(/V/, "valid");
            buffer = buffer.replace(/DCL/, "declared");
            buffer = buffer.replace(/DEF/, "defined");
            return buffer;
        }

        function parseAttr(attributes) {
            var buffer = "";
            buffer = attributes.replace(/S/, "scoped");
            buffer = buffer.replace(/W/, "writable");
            buffer = buffer.replace(/O/, "observable");
            return buffer;
        }

        var result = "";
        result += "<table class='value'>";
        result += "<tr><th>type</th><td><code>" + cx.toLink(this.meta.type) + "</code></td>";
        result += "<tr><th>parent</th><td><code>" + cx.toLink(this.meta.parent) + "</code></td>";
        result += "<tr><th>state</th><td><code class='bitmask'>" + parseStates(this.meta.states) + "</code></td></tr>";
        result += "<tr><th>attributes</th><td><code class='bitmask'>" + parseAttr(this.meta.attributes) + "</code></td></tr>";
        result += "</table>"
        return result;
    },

    // Convert object value to HTML
    toHtml: function() {

        function getValueClass(valueKind) {
            if (valueKind === 'E') {
                return 'enum';
            } else if (valueKind === 'R') {
                return 'reference';
            } else if (valueKind === 'B') {
                return 'binary';
            } else if (valueKind === 'M') {
                return 'bitmask';
            }
        }

        function primitive(s, v) {
            var valueClass = "";
            var valueString = v;

            valueClass = typeof v;

            if ((valueClass === 'string') && (v[0] === '@')) {
                if (v[1] === '@') {
                    valueString = v.substr(1, valueString.length - 1);
                } else {
                    valueString = v.substr(3, valueString.length - 3);
                    valueClass = getValueClass(v.substr(1, 1));
                    if (valueClass == 'reference') {
                        valueClass = 'normal';
                        valueString = cx.toLink(valueString);
                    }
                }
            }

            return "<td><code class=" + valueClass + ">" + valueString + "</code></td>";
        }

        function member(s, v) {
            var result = "";
            if (s.vertical) {
                result = "<tr><th>" + s.info + "</th>" + s.serializeValue(v) + "</tr>";
            } else {
                result = s.serializeValue(v);
            }
            return result;
        }

        function element(s, v) {
            return "<tr><th>" + s.info + "</th>" + s.serializeValue(v) + "</tr>";
        }

        function composite(s, v) {
            var result = "";
            result += s.serializeMembers(v);
            return result;
        }

        function collection(s, v) {
            var oldVertical = s.vertical;
            var result = "";
            s.vertical = false;

            // Print header if array is of a composite type
            if (v[0].constructor === Object) {
                result = "<tr><th></th>"
                for (var k in v[0]) {
                    result += "<th>" + k + "</th>";
                }
                result += "</tr>";
            }

            result += s.serializeElements(v);
            s.vertical = oldVertical;
            return result;
        }

        function object(s, v) {
            var buffer = "";
            s.vertical = true;
            buffer += "<table class='value'>";
            buffer += s.serializeValue(v);
            buffer += "</table>";
            return buffer;
        }

        return new cx.serializer(
            object, composite, collection, primitive, member, element
        ).serialize(this.value);
    }
}

// Create the root object
cx.root = new cx.object(undefined, "");

// Create a resolve in cx that resolves from root
cx.resolve = function(name) { return cx.root.resolve(name);}




