/*struct POINT {
  int x;
  int y;
};*/

const int X = 5;
const int Y = 6;

//POINT points[] = {{20,20}, {20,20}, {225, 225}, {225,225}};
int points[][2] = {{20,20}, {20,225}, {225, 225}, {225,20}};

int pointsLength;

int steps = 10;

void setup() {
  pinMode(X, OUTPUT);
  pinMode(Y, OUTPUT);

  pointsLength = (sizeof(points)/sizeof(*points));

  Serial.begin(9600);

  TCCR0B = 0b00000001; // x1
  TCCR0A = 0b00000011; // fast pwm
}

void loop() {/*
  digitalWrite(X, HIGH);
  digitalWrite(Y, HIGH);

  delay(1);

  digitalWrite(X, LOW);
  digitalWrite(Y, LOW);

  delay(1);*/

  for(int i = 0; i < pointsLength; i++) {

    int startPoint[2] = {points[i][0], points[i][1]};
    int endPoint[2];
    
    if(i == pointsLength - 1) {
      endPoint[0] = points[0][0];
      endPoint[1] = points[0][1];
    } else {
      endPoint[0] = points[i+1][0];
      endPoint[1] = points[i+1][1];
    }

    Serial.print("Points: (");
    Serial.print(startPoint[0]);
    Serial.print(startPoint[1]);
    Serial.print(") (");
    Serial.print(endPoint[0]);
    Serial.print(endPoint[1]);
    Serial.println(")");
    
    int xm = endPoint[0] - startPoint[0];
    int ym = endPoint[1] - startPoint[1];

    Serial.print("xm:");
    Serial.print(xm);
    Serial.print(" ym:");
    Serial.println(ym);
    
    //int subpoints[steps][2] = {};
    
    for(int i = 0; i <= steps; i++) {
      //subpoints[i][0] = xm / steps * i;
      //subpoints[i][1] = ym / steps * i;
      int x = startPoint[0] + (xm / steps * i);
      int y = startPoint[1] + (ym / steps * i);

      Serial.print(x);
      Serial.print(".");
      Serial.println(y);
      
      analogWrite(X, x);
      analogWrite(Y, y);

      //delay(1000);
    }
  }
  
}
