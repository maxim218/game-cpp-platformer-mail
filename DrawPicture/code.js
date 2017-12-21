"use strict";

let can = null;
let holst = null;

let arr = [];

function elem(s) {
    return document.getElementById(s);
}

function clearAll() {
    holst.fillStyle = '#FFFFFF';
    holst.strokeStyle = '#FFFFFF';
    holst.lineWidth = 1;
    holst.fillRect(0, 0, 400, 400);
    arr = [];
    elem('ccc').value = "#FFFFFF";
    holst.strokeStyle = '#000000';
    field.innerHTML = "";
}

function setColorDrawing(elem) {
    holst.fillStyle = elem.value;
    holst.strokeStyle = '#000000';
    holst.lineWidth = 1;

}

let xx = 0;
let yy = 0;
let comboBox = null;
let field = null;
let ccc = null;
let scale = null;

window.onload = function() {
    scale = elem("cb2");
    ccc = elem("ccc");
    comboBox = elem("cb1");
    field = elem("tttt");
    can = elem('can');
    holst = can.getContext('2d');
    clearAll();

    can.addEventListener("mousedown",function(event){
        const xMouse = parseInt(event.offsetX);
        const yMouse = parseInt(event.offsetY);
        xx = xMouse;
        yy = yMouse;
    });

    can.addEventListener("mouseup",function(event){
        const xMouse = parseInt(event.offsetX);
        const yMouse = parseInt(event.offsetY);

        let x1 = Math.min(xx, xMouse);
        let x2 = Math.max(xx, xMouse);

        let y1 = Math.min(yy, yMouse);
        let y2 = Math.max(yy, yMouse);

        let dx = x2 - x1;
        let dy = y2 - y1;

        const value = comboBox.value;

        if(value === "1") {
            holst.fillRect(x1, y1, dx, dy);
            holst.strokeRect(x1, y1, dx, dy);
            arr.push({
                type: "rectangle",
                x1: parseInt(x1),
                y1: parseInt(y1),
                dx: parseInt(dx),
                dy: parseInt(dy),
                color: ccc.value.toString()
            });
        } else {
            const xc = xx;
            const yc = yy;
            const radius = parseInt(Math.sqrt( (xMouse - xx) * (xMouse - xx) + (yMouse - yy) *  (yMouse - yy)));
            holst.beginPath();
            holst.arc(xc, yc, radius ,0, Math.PI * 2, true);
            holst.fill();
            holst.stroke();
            arr.push({
                type: "okrugnost",
                xc: parseInt(xc),
                yc: parseInt(yc),
                radius: parseInt(radius),
                color: ccc.value.toString()
            });
        }
    });
};

function getResult() {
    let answer = "";
    const k = parseInt(scale.value);

    for(let i = 0; i < arr.length; i++) {
        const obj = arr[i];

        if(obj.type === "rectangle") {
            let s = "";
            s = s + 'color.setNamedColor("' + obj.color + '");' + "\n";
            s = s + "brush.setColor(color);" + "\n";
            s = s + "my_s->addRect(xx + " + obj.x1 / k + " - dx, yy + " + obj.y1 / k + " - dy," + obj.dx / k + "," + obj.dy / k + ",pen,brush);"+ "\n";
            answer += s;
        } else {
            let s = "";
            s = s + 'color.setNamedColor("' + obj.color + '");' + "\n";
            s = s + "brush.setColor(color);" + "\n";
            s = s + "my_s->addEllipse(xx + " + (obj.xc - obj.radius) / k + " - dx, yy + " + (obj.yc - obj.radius) / k + " - dy," + (obj.radius * 2) / k + "," + (obj.radius * 2) / k + ",pen,brush);" + "\n";
            answer += s;
        }
    }

    field.innerHTML = answer;
}


