
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

document.addEventListener('DOMContentLoaded', function() {
    var main = document.getElementsByTagName("main")[0];
    var meta = thisObject['meta'];
    var value = thisObject['value'];
    var scope = thisObject['scope'];

    function catenate(text) {
        main.insertAdjacentHTML('beforeend', text);
    }

    catenate("<h1>" + meta["name"] + "</h1>");
    
    catenate("<h2 id='meta'>Meta</h2>");
    catenate(objectAsTable(meta));
    
    catenate("<h2 id='value'>Value</h2>")
    if (typeof value === 'object') {
        catenate(objectAsTable(value));
    } else {
        catenate(value);
    }
    
    catenate("<h2 id='scope'>Scope</h2>");
    if (scope.length === 0) {
        catenate("This namespace is empty.");
    } else {
        scope.forEach(function (e) {
            catenate("<h3 class='scope-object'>" + e["name"] + "</h3>");
            catenate(objectAsTable(e));
        });
    }
});

