objects = {};

document.addEventListener('DOMContentLoaded', function() {
    var child;
    var childSimpleName;
    var main;
    var meta;
    var parentName;
    var scopeIsEmpty;
    var value;
    var valueType;

    function assocArraySize(obj) {
        // http://stackoverflow.com/a/6700/11236
        var size = 0, key;
        for (key in obj) {
            if (obj.hasOwnProperty(key)) {
                size += 1;
            }
        }
        return size;
    }

    function objectAsTable(object, tableClass, tableId) {
        var buffer = "";
        buffer += "<table>";
        for (var k in object) {
            buffer += "<tr><th>" + k + "</th><td><code>" + object[k] + "</code><td></tr>";
        }
        buffer += "</table>";
        return buffer;
    }

    function objectAsDefinitionList(object, tableClass, tableId) {
        var buffer = "";
        buffer += "<dl>";
        for (var k in object) {
            buffer += "<dt>" + k + "</dt><dd>" + object[k] + "</dd>";
        }
        buffer += "</dl>";
        return buffer;
    }

    function parseStates(states) {
        var buffer = "";
        buffer = states.replace(/V/, "valid");
        buffer = buffer.replace(/DCL/, "declared");
        buffer = buffer.replace(/DEF/, "defined");
        buffer = buffer.replace(/\|/g, " | ");
        return buffer;
    }

    function parseAttributes(attributes) {
        var buffer = "";
        buffer = attributes.replace(/S/, "scoped");
        buffer = buffer.replace(/W/, "writable");
        buffer = buffer.replace(/O/, "observable");
        buffer = buffer.replace(/\|/g, " | ");
        return buffer;
    }

    function parseMetaAsTable(meta) {
        var buffer = "";
        buffer += "<table id='meta' class='meta'>";
        buffer += "<tr><th>Name</th><td>" + meta['name'] + "</td></tr>";
        buffer += "<tr><th>Type</th><td>" + meta['type'] + "</td></tr>";
        buffer += "<tr><th>States</th><td><code>" +
                  parseStates(meta['states']) +
                  "</code></td></tr>";
        buffer += "<tr><th>Attributes</th><td><code>" +
                  parseAttributes(meta['attributes']) +
                  "</code></td></tr>";
        buffer += "<tr><th>Parent</th><td>";
        if (thisName === rootName) {
            buffer += meta['parent'];
        } else {
            buffer += "<a href=\"../index.html\">" + meta['parent'] + "</a>";
        }
        buffer += "</td></tr>";
        buffer += "<tr><th>Child count</th><td>" + meta['childCount'] + "</td></tr>";
        buffer += "</table>";
        return buffer;
    }

    function parseScopeObjectAsTable(meta) {
        var buffer = "";
        buffer += "<table id='" + meta['name'] + "' class='meta'>";
        buffer += "<tr><th>Name</th><td>" + meta['name'] + "</td></tr>";
        buffer += "<tr><th>Type</th><td>" + meta['type'] + "</td></tr>";
        buffer += "<tr><th>States</th><td><code>" + parseStates(meta['states']) +
                  "</code></td></tr>";
        buffer += "<tr><th>Attributes</th><td><code>" +
                  parseAttributes(meta['attributes']) +
                  "</code></td></tr>";
        buffer += "</table>";
        return buffer;
    }

    function parseValueArrayAsList(value, ordered) {
        var buffer = "";
        if (ordered) {
            buffer += "<ul>";
        } else {
            buffer += "<ol>";
        }
        value.foreach(function (item) {
            buffer += "<li>" + item + "</li>";
        });
        if (ordered) {
            buffer += "</ul>";
        } else {
            buffer += "</ol>";
        }
        return buffer;
    }


    parentName = objects[thisName]['meta']['parent'];
    meta = objects[thisName]['meta'];
    value = objects[thisName]['value'];

    main = $("main");
    main.append("<h1>" + meta["name"] + "</h1>");
    main.append("<a href='#meta'><h2 id='meta'>Meta</h2></a>");
    main.append(parseMetaAsTable(meta));

    valueType = typeof value;
    if (valueType !== 'undefined') {
        main.append("<a href='#value'><h2 id='value'>Value</h2></a>");
        if (valueType === 'object') {
            if ($.isEmptyObject(value)) {
                main.append("Empty");
            } else {
                main.append(objectAsTable(value));
            }
        } else if (valueType === 'array') {
            main.append(parseValueArrayAsList(value));
        } else {
            main.append(value);
        }
    }
    
    scopeIsEmpty = assocArraySize(objects) <= 2;
    if (!scopeIsEmpty) {
        main.append("<a href='#scope'><h2 id='scope'>Scope</h2></a>");
        for (var childName in objects) {
            child = objects[childName];
            childSimpleName = child['meta']['name'];
            if (childName !== thisName && childName !== parentName) {
                main.append("<a href='./" + childSimpleName +
                    "/index.html'><h3 id='" + childName + "'>" +
                    childSimpleName + "</h3></a>");
                main.append(parseScopeObjectAsTable(child['meta']));
            }
        }
        
    }
});

