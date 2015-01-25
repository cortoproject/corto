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
    toLink: function(link, style) {
        var p = cx.me;
        var prefix = "";
        var result = "";
        var name = "";
        while (p.parent) {
            p = p.parent;
            prefix += "../";
        }
        var langlen = "::cortex::lang".length;
        if ((link.length > langlen) && (link.slice(0, langlen) == "::cortex::lang")) {
            prefix += "cortex/lang/";
            link = link.slice(langlen + 2, link.length);
        }

        var melen = cx.me.id().length;
        if ((link.length > melen) && (link.slice(0, melen) === cx.me.id())) {
            prefix += cx.me.id().slice(2, melen).replace("::", "/") + "/";
            link = link.slice(melen + 2, link.length);
        }

        if (style === undefined) {
            style = 'reference';
        }

        for (var i = 0, start = 0; i < link.length; i++) {
            var ch = link[i];
            if (ch === ':') {
                if (i === 0) {
                    result = "<a class='" + style + "' href='" + prefix + "index.html'>::</a>";
                } else {
                    name = link.slice(start, i);
                    if (start > 2) {
                        result += "::";
                    }
                    prefix += name + "/";
                    result += "<a class='" + style + "' href='" + prefix + "index.html'>" + name + "</a>";
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
        result += "<a class='" + style + "' href='" + prefix + "index.html'>" + name + "</a>";

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
        var p = this.parent;
        var result = this.name;
        while (p) {
            if (p.name !== "::") {
                result = p.name + "::" + result;
            } else {
                result = "::" + result;
            }
            p = p.parent;
        }
        return result;
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

    // Convert scope to HTML
    scopeToHtml: function() {
        var result = "";
        var link = "";
        var links = [];
        var size = 0;

        for (o in this.scope) { size++; }
        if (size) {
            result = "<table class='scope'><tr class='separator'>";
            result += "<tr class='separator'><td colspan='2'>Scope</td></tr>"
            for (o in this.scope) {
                result += "<tr class='child'>" + 
                    "<td><code>" + cx.toLink(this.scope[o].id()) + "</code></td>" +
                    "<td><code>" + cx.toLink(this.scope[o].meta.type) + "</code></td>" +
                    "</tr>";
            }
            result += "</table>";
        }

        return result;
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
        result += "<thead class='value'><tr><th></th><td>Metadata</td></tr></thead><tbody class='value'>"
        result += "<tr><th>type</th>" + 
                      "<td><code>" + cx.toLink(this.meta.type) + "</code></td>";
        result += "<tr><th>parent</th>" +
                      "<td><code>" + cx.toLink(this.meta.parent) + "</code></td>";
        result += "<tr><th>state</th>" +
                      "<td><code class='bitmask'>" + parseStates(this.meta.states) + "</code></td></tr>";
        result += "<tr><th>attributes</th>" +
                      "<td><code class='bitmask'>" + parseAttr(this.meta.attributes) + "</code></td></tr>";
        result += "</tbody></table>"
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

            var result = "<code class=" + valueClass + ">" + valueString + "</code>";
            if (!s.complex) {
                result = "<td>" + result + "</td>"
            }
            return result;
        }

        function member(s, v) {
            var result = "";
            var oldComplex = s.complex;

            if (s.vertical) {
                if (!(v instanceof Object)) {
                    result = "<td>" + s.serializeValue(v) + "</td>";
                } else {
                    result = s.serializeValue(v);
                }
            } else {
                if (v instanceof Object) {
                    if (!s.complex) {
                        s.complex = 1;
                        result = "<tr><th>" + s.info + "</th><td>" + 
                            "<table style='margin:0px; padding:0px; border-spacing:0px'>" + 
                            s.serializeValue(v) + "</table></td></tr>";
                        s.complex = oldComplex;
                    } else {
                        result = "<td><table class='nested'><tr><th>" + 
                            s.info + "</th><td>" + 
                            "<table style='margin:0px; padding:0px; border-spacing:0px'>" + 
                            s.serializeValue(v) + "</table></td></tr></table></td>";                  
                    }
                } else {
                    if (s.complex) {
                        result = "<td><table class='nested'><th>" + 
                            s.info + "</th><td>" + s.serializeValue(v) + "</td></tr></table></td>";
                    } else {
                        // Normal case
                        result = "<tr><th>" + s.info + "</th>" + s.serializeValue(v) + "</tr>";
                    }
                }
            }

            return result;
        }

        function element(s, v) {
            var result = "";
            var oldComplex = s.complex;
     
            s.complex = 1;      
            result = s.serializeValue(v);
            if (s.vertical) {
                result = "<tr>" + result + "</tr>";
            } else {
                if (s.info) {
                    result = ",&nbsp;" + result;
                }
            }
            s.complex = oldComplex;
            return result;
        }

        function composite(s, v) {
            var result = "";
            result += s.serializeMembers(v);
            if (!s.vertical && s.complex) {
                result = "<tr>" + result + "</tr>";
            }
            return result;
        }

        // Collect complex members for a collection header */
        function collectMembers (elem, members, depth) {
            var count = 0;
            var totalColumns = 0;
            var totalDepth = depth;

            if (elem instanceof Object) {
                if (!members[depth]) {
                    members[depth] = [];
                }
                for (var m in elem) {
                    span = collectMembers(elem[m], members, depth + 1);
                    totalColumns += span[1];
                    if (span[0] > totalDepth) { totalDepth = span[0]; }
                    count++;

                    members[depth].push({
                        "member":m, 
                        "span":span});
                }
            } else {
                totalDepth--;
                totalColumns = 1;
            }

            return [totalDepth, totalColumns];
        }

        // Create collection header
        function createHeader(members) {
            var result = "";
            for (var depth = members.length - 1; depth >= 0; depth--) {
                var row = "";
                for (var m = 0; m < members[depth].length; m++) {
                    var colstr = "";
                    var rowstr = "";
                    var rowspan = members.length - members[depth][m].span[0];
                    var colspan = members[depth][m].span[1];
                    if (colspan > 1) { colstr = " colspan='" + colspan + "'";}
                    if (rowspan > 1) { rowstr = " rowspan='" + rowspan + "'";}
                    row += "<th align='center' valign='bottom'" + colstr + rowstr + ">" + members[depth][m].member + "</th>";
                }
                result = "<tr>" + row + "</tr>" + result;
            }
            return "<thead>" + result + "</thead>";
        }

        function collection(s, v) {
            var oldVertical = s.vertical;
            var result = "";
            var oldVertical = s.vertical;      

            if (v.length) {
                if (v[0] instanceof Object) {
                    var members = [];
                    s.vertical = true;
                    collectMembers(v[0], members, 0);
                    result += "<td><table class='nested'>" + createHeader(members);
                    result += "<tbody>" + s.serializeElements(v) + "</tbody>";
                    result += "</table></td>";
                    if (!s.complex) {
                        result = "<th></th>" + result;
                    }
                } else {
                    s.vertical = false;
                    if (!s.complex) {
                        result = "<tr><th></th><td>" + s.serializeElements(v) + "</td></tr>"
                    } else {
                        result += "<tr>" + s.serializeElements(v) + "</tr>";
                    }
                }
            } else {
                result += "<td><code>empty</code></td>";
            }

            s.vertical = oldVertical;

            return result;
        }

        function object(s, v) {
            var buffer = "";
            var size = 0;
            if (typeof v == 'object') {
                for (k in v) {size ++;}
            } else {
                size = 1;
            }

            buffer += "<table class='value'>";
            buffer += "<thead class='value'><tr><th></th><td>Value</td></tr></thead><tbody class='value'>";
            if (size) {
                if (!(v instanceof Object)) {
                    buffer += "<th class='value'></th>";
                }
                buffer += s.serializeValue(v);
            } else {
                buffer += "<tr><th></th><td><code>empty</code></td></tr>";
            }
            buffer += "</tbody></table>";
            return buffer;
        }

        var s = new cx.serializer(
            object, composite, collection, primitive, member, element
        )
        s.complex = 0;
        return s.serialize(this.value);
    }
}

// Create the root object
cx.root = new cx.object(undefined, "");
cx.root.meta.type = "::cortex::lang::void";

// Create a resolve in cx that resolves from root
cx.resolve = function(name) { return cx.root.resolve(name);}




