let SIZE_ROOM = 40;
let SIZE_LEMIM = 12;
let COLORS = ['rgb(115, 101, 152)', 'rgb(174, 168, 211)'];
let START_COLORS = ['rgb(232, 88, 69)', 'rgb(255, 144, 130)'];
let END_COLORS = ['rgb(64, 209, 108)', 'rgb(130, 255, 167)'];
let BACKGROUND_COLOR = 'rgb(48, 51, 56)';

let MAX_SIZE = 0;
let MARGIN = 0;
let GOOD_SIZE = 0;
let MAX_COORD = 0;
let MIN_COORD = 2147483647;
let MAX_STEPS = 0;

let SPEED = 100;

let BUTTON_RAND;
let BUTTON_RESTART;

let LEMIN_TAB = [];
let STEP = 1;
let ARRIVED = 0;

function Button(x, y) {
  this.x = x;
  this.y = y;
  this.height = 30;
  this.width = 180;

  this.display = (color, display_text) => {
    stroke(color);
    fill(255, 150);
    rect(this.x, this.y, this.width, this.height, 5);
    fill(BACKGROUND_COLOR);
    noStroke();
    textFont("Helvetica");
    textSize(12);
    textAlign(CENTER);
    text(display_text, this.x + this.width / 2, this.y + this.height / 2 + 5);
  }
}

class lemin {
  constructor(lemin_name) {
    this.name = lemin_name;
    this.from = MAP.rooms[MAP.start];
  }
}

window.onresize = () => {
  resizeCanvas(windowWidth, windowHeight);
  set_vars();
}

function setup() {
  createCanvas(windowWidth, windowHeight);
  angleMode(DEGREES);
  set_vars();
  set_rooms_var();
}

function draw() {
  background(BACKGROUND_COLOR);
  draw_links();
  Object.keys(MAP.rooms).forEach(function(name){
    if (MAP.start === name){
      add_room(
        map(MAP.rooms[name].x, MIN_COORD, MAX_COORD, MARGIN, windowWidth - MARGIN),
        map(MAP.rooms[name].y, MIN_COORD, MAX_COORD, MARGIN, windowHeight - MARGIN),
        END_COLORS[0],
        END_COLORS[1]
      );
    } else if (MAP.end === name) {
      add_room(
        map(MAP.rooms[name].x, MIN_COORD, MAX_COORD, MARGIN, windowWidth - MARGIN),
        map(MAP.rooms[name].y, MIN_COORD, MAX_COORD, MARGIN, windowHeight - MARGIN),
        START_COLORS[0],
        START_COLORS[1]
      );
    } else {
      add_room(
        map(MAP.rooms[name].x, MIN_COORD, MAX_COORD, MARGIN, windowWidth - MARGIN),
        map(MAP.rooms[name].y, MIN_COORD, MAX_COORD, MARGIN, windowHeight - MARGIN),
        COLORS[0],
        COLORS[1]
      );
    }
  });
  let step_id = parseInt((STEP - 1) / SPEED);
  if (step_id < MAP.steps.length && STEP > 1) {
    Object.keys(MAP.steps[step_id]).forEach(function(lemin_name){
      let room_name = MAP.steps[step_id][lemin_name];
      let lemin_id = parseInt(lemin_name.substring(1)) - 1;
      if (LEMIN_TAB.length <= lemin_id) {
        LEMIN_TAB.push(new lemin(lemin_name));
      } else if (STEP % SPEED === 0) {
        LEMIN_TAB[lemin_id].from = MAP.rooms[room_name];
        if (room_name === MAP.end && STEP / SPEED < MAP.steps.length) {
          ARRIVED += 1;
        }
      }
      put_lemin(LEMIN_TAB[lemin_id].from, MAP.rooms[room_name], STEP % SPEED);
    });
  } else {
    put_lemin(MAP.rooms[MAP.start], MAP.rooms[MAP.start], 0);
  }
  if (STEP / SPEED < MAP.steps.length) {
    STEP += 1;
  } else {
    ARRIVED = LEMIN_TAB.length;
  }
  BUTTON_RAND.display(BACKGROUND_COLOR, "Randomize x and y");
  BUTTON_RESTART.display(BACKGROUND_COLOR, "Reset");
  draw_info();
}

function mousePressed(data) {
  if (data.x >= BUTTON_RAND.x && data.x <= BUTTON_RAND.x + BUTTON_RAND.width
    && data.y >= BUTTON_RAND.y && data.y <= BUTTON_RAND.y + BUTTON_RAND.height) {
      randomize();
  }
  if (data.x >= BUTTON_RESTART.x && data.x <= BUTTON_RESTART.x + BUTTON_RESTART.width
    && data.y >= BUTTON_RESTART.y && data.y <= BUTTON_RESTART.y + BUTTON_RESTART.height) {
      STEP = 1;
      ARRIVED = 0;
      LEMIN_TAB = [];
  }
}

function keyPressed() {
  if (keyCode === 32) {
    STEP = 1;
    ARRIVED = 0;
    LEMIN_TAB = [];
  } else if (keyCode === 88) {
    randomize();
  } else if (keyCode === UP_ARROW && SPEED > 1) {
    SPEED -= 1;
  } else if (keyCode === DOWN_ARROW) {
    SPEED += 1;
  } else if (keyCode === 77) {
    SPEED = 1;
    STEP = 1;
    ARRIVED = 0;
    LEMIN_TAB = [];
  }
}

function set_rooms_var() {
  Object.keys(MAP.rooms).forEach(function(name){
    if (MAP.rooms[name].x > MAX_COORD) {
      MAX_COORD = MAP.rooms[name].x;
    }
    else if (MAP.rooms[name].x < MIN_COORD) {
      MIN_COORD = MAP.rooms[name].x;
    }
    if (MAP.rooms[name].y > MAX_COORD) {
      MAX_COORD = MAP.rooms[name].y;
    }
    else if (MAP.rooms[name].y < MIN_COORD) {
      MIN_COORD = MAP.rooms[name].y;
    }
  });
}

function set_vars() {
  MAX_SIZE = ((windowWidth < windowHeight) ? windowWidth : windowHeight);
  MARGIN = MAX_SIZE * 0.1;
  GOOD_SIZE = MAX_SIZE - MARGIN;
  BUTTON_RAND = new Button(windowWidth - 210, 10);
  BUTTON_RESTART = new Button(windowWidth - 420, 10);
  MAX_STEPS = MAP.steps.length;
}

function randomize() {
  Object.keys(MAP.rooms).forEach(function(name){
    MAP.rooms[name].x = map(Math.random(), 0, 1, MIN_COORD, MAX_COORD);
    MAP.rooms[name].y = map(Math.random(), 0, 1, MIN_COORD, MAX_COORD);
  });
}

function put_lemin(input, output, depth) {
  fill("rgb(255, 255, 255)");
  strokeWeight(2);
  noStroke();
  ellipse(
    map(map(depth, 0, SPEED, input.x, output.x), MIN_COORD, MAX_COORD, MARGIN, windowWidth - MARGIN),
    map(map(depth, 0, SPEED, input.y, output.y), MIN_COORD, MAX_COORD, MARGIN, windowHeight - MARGIN),
    SIZE_LEMIM,
    SIZE_LEMIM
  );
}

function draw_info() {
  fill(255);
  textAlign(LEFT);
  textFont("Helvetica");
  textSize(30);
  text(ARRIVED + "/" + MAP.nb_ant + " ants", 20, 35);
}

function draw_links() {
  let cord1;
  let cord2;
  stroke(COLORS[1]);
  for (var i = 0; i < MAP.links.length; i++) {
   cord1 = MAP.rooms[MAP.links[i][0]];
   cord2 = MAP.rooms[MAP.links[i][1]];
   line(
     map(cord1.x, MIN_COORD, MAX_COORD, MARGIN, windowWidth - MARGIN),
     map(cord1.y, MIN_COORD, MAX_COORD, MARGIN, windowHeight - MARGIN),
     map(cord2.x, MIN_COORD, MAX_COORD, MARGIN, windowWidth - MARGIN),
     map(cord2.y, MIN_COORD, MAX_COORD, MARGIN, windowHeight - MARGIN)
   );
 }
}

function add_room(x, y, fillColor, strokeColor) {
  fill(fillColor);
  strokeWeight(2);
  stroke(strokeColor);
  ellipse(x, y, SIZE_ROOM, SIZE_ROOM);
}
