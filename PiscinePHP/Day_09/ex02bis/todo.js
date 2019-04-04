function addElement() {
    if ((name = window.prompt("Nouveau to do :", "")).length) {
        let list = $("#ft_list");
        let div = document.createElement("div");
        let data = Math.random().toString(36).substr(2);
        list.prepend(div);
        div.outerHTML = "<div id='"
        + data
        + "' onclick='if(window.confirm(\"Êtes-vous sûr ?\")){$(\"#"
        + data
        + "\").remove(); saveTodo($(\"#ft_list\"));}'>"
        + name + "</div>"
        saveTodo(list);
    }
}

function saveTodo(parent) {
    document.cookie = "todolist=" + escape(parent[0].outerHTML);
}

function startTodo() {
    let cookie = unescape(document.cookie).replace("todolist=", "");
    if (cookie.length)
        $("#ft_list")[0].outerHTML = cookie;
}
