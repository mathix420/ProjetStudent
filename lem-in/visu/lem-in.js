let SIZE_ROOM = 40;
let COLORS = ['rgb(115, 101, 152)', 'rgb(174, 168, 211)'];
let START_COLORS = ['rgb(232, 88, 69)', 'rgb(255, 144, 130)'];
let END_COLORS = ['rgb(64, 209, 108)', 'rgb(130, 255, 167)'];

window.onresize = () => {
  resizeCanvas(windowWidth, windowHeight);
}

function setup() {
  createCanvas(windowWidth, windowHeight);
  angleMode(DEGREES);
  console.log(MAP);
}

function draw() {
  background(48, 51, 56);
  for (var i = 0; i < MAP.rooms.length; i++) {
    if (MAP.start === MAP.rooms[i].name){
      add_room(MAP.rooms[i].x * 50 + 100, MAP.rooms[i].y * 50 + 100, START_COLORS[0], START_COLORS[1]);
    } else if (MAP.end === MAP.rooms[i].name) {
      add_room(MAP.rooms[i].x * 50 + 100, MAP.rooms[i].y * 50 + 100, END_COLORS[0], END_COLORS[1]);
    } else {
      add_room(MAP.rooms[i].x * 50 + 100, MAP.rooms[i].y * 50 + 100, COLORS[0], COLORS[1]);
    }
  }
}

function add_room(x, y, fillColor, strokeColor) {
  fill(fillColor);
  strokeWeight(2);
  stroke(strokeColor);
  ellipse(x, y, SIZE_ROOM, SIZE_ROOM);
}
