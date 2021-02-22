
import oscP5.*;
import netP5.*;
  
OscP5 oscP5;
NetAddress myRemoteLocation;

float amount = 15;
float num = 0;
float filler = 0;
float second = 0;
float thirth = 0;

void setup() {
  size(900,1000);
  frameRate(25);
  oscP5 = new OscP5(this, 8080);
  myRemoteLocation = new NetAddress("192.168.20.53", 8080);
  stroke(255, 255, 255, 140);
}


void draw() {
  fill(0, 20);
  rect(-1, -1, width+1, height+1);
  translate(width/2, height/2);
  for (int i = 0; i < 360; i+=amount) {
    float m = sin(radians(i+num)) * second;
    float p = cos(radians(i+num)) * second;
    float m2 = sin(radians(i+amount-num)) * filler;
    float p2 = cos(radians(i+amount-num)) * filler;
    
    noFill();
    stroke(m+filler*random(thirth), m+filler*random(thirth), m+filler*random(thirth), filler);
    bezier(m, p, m-m2, p-p2, m2-m, p2-p, m2, p2);
    bezier(m, p, m+m2, p+p2, m2+m, p2+p, m2, p2);
    ellipse(p, m, 5, 5);
    ellipse(m2, p2, 5, 5);
  }
  num += 0.5;
}

/* incoming osc message are forwarded to the oscEvent method. */
void oscEvent(OscMessage theOscMessage) {
  /* check if theOscMessage has the address pattern we are looking for. */  
  if(theOscMessage.checkAddrPattern("/test")==true) {
    /* check if the typetag is the right one. */
    if(theOscMessage.checkTypetag("fff")) {
      float firstValue = theOscMessage.get(0).floatValue();  // get the first osc argument
      float secondValue = theOscMessage.get(1).floatValue()*200; // get the second osc argument
      float thirdValue = theOscMessage.get(2).floatValue()*100; // get the third osc argument
      filler = firstValue;
      if(secondValue < 0) {
        secondValue = secondValue*-1;
      }
      if(thirdValue < 0) {
        thirdValue = thirdValue*-1;
      }
      second = secondValue;
      thirth = thirdValue;
      print("### received an osc message /test with typetag ifs.");
      println(" values1: "+firstValue);
      println(" values2: "+secondValue);
      println(" values3: "+thirdValue);
      return;
    }
  }
  println("### received an osc message. with address pattern "+ theOscMessage.addrPattern()+" typetag "+ theOscMessage.typetag());
}
