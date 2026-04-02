import processing.serial.*;
import processing.sound.*;

Serial port;

AudioIn mic;
FFT fft;

float spectrum[] = new float[512];

String signal="R";
int timer=0;
int db=0;
int penalty=0;

boolean ambulance=false;

void setup()
{
  size(700,500);

  println(Serial.list());
  port = new Serial(this, Serial.list()[0],9600);
  port.bufferUntil('\n');

  mic = new AudioIn(this,0);
  mic.start();

  fft = new FFT(this,1024);
  fft.input(mic);
}

void draw()
{
  background(30);

  fft.analyze(spectrum);

  ambulance=false;

  for(int i=0;i<spectrum.length;i++)
  {
    float freq = i*(44100.0/1024);

    if(freq>700 && freq<1500 && spectrum[i] > 0.04)
    {
      ambulance=true;
    }
  }

  if(ambulance)
  {
    port.write('A');
  }

  textSize(30);
  fill(255);
  text("SMART TRAFFIC CONTROL",140,60);

  textSize(20);
  text("Decibel Level : "+db+" dB",250,120);
  text("Timer : "+timer,300,160);

  if(penalty==1)
  {
    fill(255,0,0);
    text("PENALTY +10 ADDED",240,200);
  }

  if(ambulance)
  {
    fill(0,255,255);
    text("AMBULANCE DETECTED",230,240);
  }

  drawLights();
  drawFFT();
}

void drawLights()
{
  if(signal.equals("R"))
  fill(255,0,0);
  else fill(70);
  ellipse(350,300,80,80);

  if(signal.equals("Y"))
  fill(255,255,0);
  else fill(70);
  ellipse(350,380,80,80);

  if(signal.equals("G"))
  fill(0,255,0);
  else fill(70);
  ellipse(350,460,80,80);
}

void drawFFT()
{
  stroke(0,255,255);

  for(int i=0;i<spectrum.length;i++)
  {
    float x = i*2;
    float h = spectrum[i]*200;

    line(x,height,x,height-h);
  }
}

void serialEvent(Serial port)
{
  String data = port.readStringUntil('\n');

  if(data!=null)
  {
    data = trim(data);

    String values[] = split(data,',');

    if(values.length==4)
    {
      signal = values[0];
      timer = int(values[1]);
      db = int(values[2]);
      penalty = int(values[3]);
    }
  }
}
