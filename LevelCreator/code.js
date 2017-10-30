"use strict";


let arr = [];
for(let i = 0; i < 200; i++) {
    arr[i] = [];
}

for(let i = 0; i < 200; i++){
    for(let j = 0; j < 400; j++) {
        arr[i][j] = 0;
    }
}

let mass = [];


function elem(s){
    return document.getElementById(s.toString());
}

let holst = null;

function drawKv(i, j, color){
    i = parseInt(i);
    j = parseInt(j);
    color = color.toString();
    holst.fillStyle = color;
    holst.fillRect(j * 10, i * 10, 10, 10);
    holst.strokeRect(j * 10, i * 10, 10, 10);
}

function drawEmpty(i, j){
    drawKv(i, j, "#859fff");
}

function drawLittleWall(i, j) {
    drawKv(i, j, "#ff2f1b");
    arr[i][j] = 1;
}

function drawBigWall(i, j) {
    drawLittleWall(i, j);
    drawLittleWall(i, j + 1);
    drawLittleWall(i + 1, j);
    drawLittleWall(i + 1, j + 1);
}

function drawBigElement(i, j, s){
    let xxx = s.toString().split("");
    let number = parseInt(xxx[1]);

    let color = "";

    switch (number) {
        case 2: color = "#FFFFFF"; break;
        case 3: color = "#40ff23"; break;
        case 4: color = "#000000"; break;
        case 5: color = "#4402ff"; break;
        case 6: color = "#33a327"; break;
        case 7: color = "#cdcdcd"; break;
    }

    holst.fillStyle = color;
    holst.fillRect(j * 10, i * 10, 20, 20);
    holst.strokeRect(j * 10, i * 10, 20, 20);

    mass.push({
       i: i,
       j: j,
       n: number
    });
}

function getResult() {
    let answer = "";
    for(let i = 0; i < mass.length; i++) {
        const obj = mass[i];
        answer = answer + obj.i + " " + obj.j + " " + obj.n + " ";
    }
    elem('t2').value = answer;

    let result = "";
    for(let i = 0; i < 200; i++){
        for(let j = 0; j < 400; j++){
           const value = arr[i][j];

           if(value === 1) {
               result = result + i + " " + j + " ";
           }
        }
    }
    elem('t1').value = result;
}

function eee(s){
    elem('typeContent').innerHTML = s.toString();
}


elem('can').addEventListener("click",function(event){
    const xMouse = event.offsetX;
    const yMouse = event.offsetY;

    const xx = parseInt(xMouse / 10);
    const yy = parseInt(yMouse / 10);

    const s = elem('typeContent').innerHTML.toString();

    if(s === "wall"){
        drawBigWall(yy, xx);
    } else {
        drawBigElement(yy, xx, s)
    }
});

window.onload = function() {
    holst = elem('can').getContext('2d');
    holst.strokeStyle = "#000000";
    holst.lineWidth = 1;

    for(let i = 0; i < 200; i++){
        for(let j = 0; j < 400; j++){
            drawEmpty(i, j);
        }
    }

    for(let i = 0; i < 200; i++){
        drawLittleWall(i, 0);
        drawLittleWall(i, 399);
        arr[i][0] = 0;
        arr[i][399] = 0;
    }

    for(let i = 0; i < 400; i++){
        drawLittleWall(0, i);
        drawLittleWall(199, i);
        arr[0][i] = 0;
        arr[199][i] = 0;
    }
};
