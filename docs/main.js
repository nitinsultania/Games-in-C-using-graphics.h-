function activate() {
    cards = document.getElementsByClassName("card");
    for (i = 0; i < cards.length; i++) {
        card = cards[i];
        obj = card.getElementsByTagName("img")[0];
        let a = i;
        obj.addEventListener("click", function () {
            showimg(a);
        });
    }
    document.getElementById('close').addEventListener("click", closeimg);
    document.getElementById('previous').addEventListener("click", previousimage);
    document.getElementById('next').addEventListener("click", nextimg);
}

function closeimg() {
    document.getElementById("imgbox").style.display = "none";
    document.body.style.overflowY = "scroll";
}

let current = 1;
let img;

let name = ["Chess", "Ludo", "Brick Breaker", "Tic Tac Toe", "Tower of Hanoi"];
let path = ["chess", "ludo", "brick breaker", "tic-tac-toe", "tower of hanoi"];
let total = [5, 4, 3, 5, 3];

function showimg(i) {
    document.getElementById("imgbox").style.display = "block";
    document.body.style.overflowY = "hidden";
    document.getElementById("imgtag").innerHTML = name[i];
    current = 1;
    img = i;
    updateimg();
}

function updateimg() {
    if (current == 1) {
        document.getElementById('previous').disabled = true;
    } else {
        document.getElementById('previous').disabled = false;
    }
    if (current == total[img]) {
        document.getElementById('next').disabled = true;
    } else {
        document.getElementById('next').disabled = false;
    }
    document.getElementById("current").innerHTML = current;
    document.getElementById("total").innerHTML = total[img];
    document.getElementById("img").src = "../" + path[img] + "/pic" + current + ".jpg";
}

function nextimg() {
    current++;
    updateimg();
}

function previousimage() {
    current--;
    updateimg();
}