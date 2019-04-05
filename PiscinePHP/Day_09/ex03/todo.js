function get_todo() {
    $.ajax({
        type: "get",
        data: "",
        url: "select.php",
        cache: false,
        success: (html) => {
            $("#ft_list")[0].innerHTML = html;
        }
    });
}

function add_todo() {
    text = $("#todo").val();
    id = $("#ft_list")[0].childElementCount;
    post_data = "text=" + text + "&id=" + id;
    if (text.length) {
        $.ajax({
            type: "post",
            data: post_data,
            url: "insert.php",
            cache: false,
            success: () => {
                get_todo();
                $("#todo").val('');
            }
        });
    }
}

function del_todo(id) {
    max_id = $("#ft_list")[0].childElementCount;
    post_data = "id=" + id;
    if (!isNaN(id)) {
        $.ajax({
            type: "post",
            data: post_data,
            url: "delete.php",
            cache: false,
            success: () => {
                get_todo();
            }
        });
    }
}

function keydown(elem) {
    if (event.code == "Enter") {
        add_todo();
    }
}