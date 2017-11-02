// 链表
function LNode() {
    this.data = null;
    this.next = null;
}
function createLink(head, n) {
    var i;
    head.data = n;
    for (i = n; i > 0; i--) {
        var newNode = new LNode();
        newNode.data = Math.floor(Math.random() * 10 + 1);
        newNode.next = head.next;
        head.next = newNode;
    }
}
function getElem(LinkList, i) {
    if (!LinkList.next) {
        return;
    }
    var p = LinkList.next;
    var j = 1;
    while (p && j < i) {
        p = p.next;
        ++j;
    }
    if (!p || j > i) {
        return;
    }
    return p.data;
}
function getIndexs(LinkList, value) {
    if (!LinkList.next) {
        return;
    }
    var p = LinkList.next;
    var indexs = new Array();
    var len = 0;
    var i = 1;
    while (p) {
        if (p.data === value) {
            indexs[len] = i;
            len++;
        }
        p = p.next;
        i++;
    }
    return indexs;
}
function insertElem(LinkList, pos, e) {
    if (!LinkList.next) {
        return;
    }
    var p = LinkList;
    var i = 0;
    while (p && i < pos - 1) {
        p = p.next;
        i++;
    }
    if (!p || i > pos - 1) {
        return;
    }
    var s = new LNode();
    s.data = e;
    s.next = p.next;
    p.next = s;
    LinkList.data++;
}
function consAll(LinkList) {
    var list = '';
    var p = LinkList.next;
    while (p) {
        list += p.data + ', ';
        p = p.next;
    }
    console.log(list);
}
function deleteElem(LinkList, i) {
    if (!LinkList.next) {
        return;
    }
    var p = LinkList.next;
    var j = 1;
    var e;
    var q;
    while (p && j < i - 1) {
        p = p.next;
        ++j;
    }
    if (!p || j > i - 1) {
        return;
    }
    q = p.next;
    p.next = q.next;
    // 由于js的垃圾回收机制，不需要手动释放内存
    LinkList.data--;
    return e;
}
function getLenth(LinkList) {
    if (!LinkList.next) {
        return 0;
    }
    var p = LinkList.next;
    var j = 0;
    while (p) {
        p = p.next;
        j++;
    }
    return j;
    // 由于我把表长存在头结点的data中，所以可以直接 return LinkList.data
}
function test() {
    var L = new LNode();
    createLink(L, 10);
    consAll(L);
    console.log(getIndexs(L, 5));
    console.log(getElem(L, 4));
    insertElem(L, 3, 999);
    consAll(L);
    deleteElem(L, 7);
    consAll(L);
    console.log(getLenth(L));
}
test();
