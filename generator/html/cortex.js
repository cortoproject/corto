// Define cx object
cx = {
    object: function(parent, name) {
        this.parent = parent;
        this.name = name;
        this.scope = {};
        this.value = {};
        this.meta = {};
    },

    serializer: function(object, composite, collection, primitive, member, element, base) {
        this.serializeObject = object;
        this.serializeComposite = composite;
        this.serializeCollection = collection;
        this.serializePrimitive = primitive;
        this.serializeMember = member;
        this.serializeElement = element;
        this.serializeBase = base;
    },

    setMe: function(name) {
        this.me = cx.resolve(name);
    },

    // Convert reference string to a link
    toLink: function(link, style, fullLink) {
        var p = cx.me;
        var prefix = "";
        var result = "";
        var name = "";
        var nesting = 0;
        var i = 0;
        var itsMe = (cx.me.id() === link)

        while (p.parent) {
            p = p.parent;
            prefix += "../";
        }

        if (!fullLink) {
            var melen = cx.me.id().length;
            if ((link.length > melen) && (link.slice(0, melen) === cx.me.id())) {
                if (cx.me.id() != "::") {
                    prefix += cx.me.id().slice(2, melen).replace(new RegExp("\:\:", 'g'), "/") + "/";
                    link = link.slice(melen + 2, link.length);
                } else {
                    link = link.slice(melen, link.length);
                }
            } else {
                var langlen = "::cortex::lang".length;
                if ((link.length > langlen) && (link.slice(0, langlen) == "::cortex::lang")) {
                    prefix += "cortex/lang/";
                    link = link.slice(langlen + 2, link.length);
                }
            }
        }

        if (style === undefined) {
            style = 'reference';
        }

        for (i = 0, start = 0; i < link.length; i++) {
            var ch = link[i];
            if (!nesting && (ch === ':')) {
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
            } else if ((ch === '(') || (ch === '{')) {
                nesting++;
            } else if ((ch === ')') || (ch === '}')) {
                nesting--;
            }
        }

        name = link.slice(start, i);
        prefix += name + "/";
        if (start > 2) {
            result += "::";
        }

        if (itsMe && fullLink) {
            result += "<span class='me'>" + name + "</span>";
        } else {
            result += "<a class='" + style + "' href='" + prefix + "index.html'>" + name + "</a>";
        }

        return result;        
    },

    primitiveToString: function(v) {
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

        if (valueClass === 'string') {
            valueString = "\"" + valueString + "\"";
        }

        return "<code class=" + valueClass + ">" + valueString + "</code>";
    },

    toString: function(v) {
        function primitive(s, v) {
            return cx.primitiveToString(v);
        }

        function composite(s, v) {
            s.count = 0;
            return "{" + s.serializeMembers(v) + "}";
        }

        function collection(s, v) {
            s.count = 0;
            return "{" + s.serializeElements(v) + "}";
        }

        function member(s, v) {
            var result = "";
            if (s.count > 0) {
                result = "&nbsp;";
            }
            s.count++;
            return result + s.info + "=" + s.serializeValue(v);
        }

        function element(s, v) {
            var result = "";
            if (s.count > 0) {
                result = ",&nbsp;";
            }
            s.count++;
            return result + s.serializeValue(v);
        }

        var s = new cx.serializer(
            undefined, composite, collection, primitive, member, element
        )
        s.count = 0;
        return "<code>" + s.serialize(v) + "</code>";   
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
            if (k[0] != '@') {
                this.info = k;
                result += this.serializeMember(this, o[k]);
            } else {
                this.info = k.slice(1, k.length);
                result += this.serializeBase(this, o[k]);
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
        if (this.serializeObject === undefined) {
            this.serializeObject = function(s, o) {return s.serializeValue(o)};
        }
        if (this.serializeBase === undefined) {
            this.serializeBase = function(s, o) {return s.serializeValue(o)};
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
        if (!result) {
            result = "::";
        }
        return result;
    },

    // Resolve object
    resolve: function(fullname) {
        var scope = this;
        var o = undefined;

        if (fullname == "::") {
            o = cx.root;
        } else {

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

        result = "<table id='scopeTable' class='value'>";
        result += "<thead class='value'><tr><td>Scope<img id='scopeIcon'></img></td></tr></thead>";
        result += "<tbody class='value'>";
        result += "<tr><td><div id='scopeContent'><table>";

        if (this.parent) {
            result += "<tr>" + 
                    "<td><code><img id='upIcon'></img><a class='reference' href='../index.html'>..</a></code></td>" +
                    "</tr>";
        }

        for (o in this.scope) { size++; }
        if (size) {
            for (o in this.scope) {
                result += "<tr>" + 
                    "<td><code> <img id='objectIcon'></img>" + cx.toLink(this.scope[o].id()) + "</code></td>" +
                    "</tr>";
            }
        } else {
            result += "<tr><td></td></tr>";
        }
        result += "</table></div></td></tr>";
        result += "<tr><td></td></tr></tbody>";

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
        result += "<table id='metaTable' class='value'>";
        result += "<thead class='value'><tr><th></th><td>Metadata<img id='metaIcon'></img></td></tr></thead><tbody class='value'>"
        result += "<tr><th>type</th>" + 
                      "<td><code>" + cx.toLink(this.meta.type) + "</code></td>";
        if (this.meta.parent) {
            result += "<tr><th>parent</th>" +
                      "<td><code>" + cx.toLink(this.meta.parent) + "</code></td>";
        }
        result += "<tr><th>state</th>" +
                      "<td><code class='bitmask'>" + parseStates(this.meta.states) + "</code></td></tr>";
        result += "<tr><th>attributes</th>" +
                      "<td><code class='bitmask'>" + parseAttr(this.meta.attributes) + "</code></td></tr>";
        result += "</tbody></table>";
        return result;
    },

    // Convert object value to HTML
    toHtml: function() {
        // Initialize table
        $( document ).ready( function() {
           $("#valueTable tr[data-depth!=1]").hide();
           $("#valueTable tr[data-depth=1]").find('span.collapse').hide();
           $("#valueTable tr[data-depth!=1]").find('span.collapse').hide();
           $("#valueTable td.dummy").hide();
        })

        $(function() {
            $('#valueTable').on('click', '.toggle', function () {
                //Gets all <tr>'s  of greater depth below element in the table
                var findChildren = function (tr) {
                    var depth = tr.data('depth');
                    return tr.nextUntil($('tr').filter(function () {
                        return $(this).data('depth') <= depth;
                    }));
                };

                var el = $(this);
                var tr = el.closest('tr'); //Get <tr> parent of toggle button
                var children = findChildren(tr);

                //Remove already collapsed nodes from children so that we don't
                //make them visible. 
                var subnodes = children.filter('.expand');
                subnodes.each(function () {
                    var subnode = $(this);
                    var subnodeChildren = findChildren(subnode);
                    children = children.not(subnodeChildren);
                });

                //Change icon and hide/show children
                if (tr.hasClass('collapse')) {
                    tr.removeClass('collapse').addClass('expand');
                    tr.find('span.collapse').hide();
                    tr.find('span.expand').show();
                    tr.find('td.complex').show();
                    tr.find('td.dummy').hide();
                    children.hide();
                } else {
                    tr.find('span.collapse').show();
                    tr.find('span.expand').hide();
                    tr.find('td.complex').hide();
                    tr.find('td.dummy').show();
                    tr.removeClass('expand').addClass('collapse');
                    children.show();
                }
                return children;
            });
        });

        function primitive(s, v) {
            return cx.primitiveToString(v);
        }

        function indent(level) {
            var result = "";
            for(var i = 0; i < (level-1); i++) {
                result += "&nbsp;";
            }
            return "<code>" + result + "</code>";
        }

        function arrow() {
            return "<span class='expand'>&#9654</span><span class='collapse'>&#9660;</span>"
        }

        function memberString(level, name, isObject) {
            var result = "";
            if (isObject) {
                result = indent(level) + arrow() + "&nbsp;" + name;
            } else {
                result = indent(level) + name;
            }
            return result;
        }

        function member(s, v) {
            var result = "";

            if (v instanceof Object) {
                collapse = "class='expand toggle'";
                result = "<tr " + collapse + " data-depth='" + s.level + "'><th>" + 
                    memberString(s.level, s.info, true) + "</th><td class='dummy'></td><td class='complex'>" + 
                    cx.toString(v) +
                    "</td></tr>";
                s.level++;
                result += s.serializeValue(v);
                s.level--;
            } else {
                collapse = "class='expand'";
                result = "<tr " + collapse + " data-depth='" + s.level + "'><th>" + 
                    memberString(s.level, s.info, false) + "</th><td>" + s.serializeValue(v) + "</td></tr>";
            }
            
            return result;
        }

        function base(s, v) {
            var result = "";
            s.baseArray.push(s.info);
            result = s.serializeValue(v);
            if (!s.baseAdded) {
                result = "<tr data-depth='1'><th class='base'></th><td class='base'>" + 
                    s.baseArray[s.baseArray.length - 1] + "</td></tr>" + result;
                s.baseArray.pop();
            }

            result = result + "<tr data-depth='1'><th class='base'></th><td class='base'>" + 
                s.baseArray[s.baseArray.length - 1] + "</td></tr>";
            s.baseArray.pop();

            s.baseAdded++;

            return result;
        }

        function object(s, v) {
            var result = "";
            var size = 0;

            s.level = 1;
            s.baseArray = [ s.me.meta.type ];
            s.baseAdded = 0;

            if (typeof v == 'object') {
                for (k in v) {size ++;}
            } else {
                size = 1;
            }

            result += "<table id='valueTable' class='value'>";
            result += "<thead class='value'><tr data-depth='1'><th></th><td>Value<img id='valueIcon'></img></td></tr></thead><tbody class='value'>";
            if (size) {
                var value = s.serializeValue(v);
                if (!(v instanceof Object)) {
                    value = "<tr data-depth='1'><th class='value'></th>" + "<td>" + value + "</td></tr>";
                }
                result += value;
            } else {
                result += "<tr data-depth='1'><th></th><td><code>empty</code></td></tr>";
            }
            result += "</tbody></table>";
            return result;
        }

        var s = new cx.serializer(
            object, undefined, undefined, primitive, member, member, base
        )
        s.me = this;
        return s.serialize(this.value);
    }
}

// Create the root object
cx.root = new cx.object(undefined, "");
cx.root.meta.type = "::cortex::lang::object";

// Create a resolve in cx that resolves from root
cx.resolve = function(name) { return cx.root.resolve(name);}




