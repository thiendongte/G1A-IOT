#include <LiquidCrystal.h>

#define button1 11
#define button2 10
#define button3 9
#define button4 8
#define led 13
#define reset 12

LiquidCrystal lcd (7, 6, 5, 4, 3, 2);


int ButtonState_1 = 0;
int LastButtonState_1 = 0;

int ButtonState_2 = 0;
int LastButtonState_2 = 0;

int ButtonState_3 = 0;
int LastButtonState_3 = 0;

int ButtonState_4 = 0;
int LastButtonState_4 = 0;

int buoc = 0;

int sttdoan = 1;
int sttdouong = 1;

int soluong = 1;

int dachondoan = 0;
int dachondouong = 0;

unsigned long time;



void setup() {
  Serial.begin(9600);
  digitalWrite(reset, HIGH);
  time = millis();
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(reset, OUTPUT);
  pinMode(led, OUTPUT);
  lcd.begin(16, 2);
  chaomung();
}

void chaomung() {
  lcd.setCursor(3, 0);
  lcd.print("CHAO MUNG");
  lcd.setCursor(3, 1);
  lcd.print("QUY KHACH");
}


void travephim() {
  ButtonState_1 == LastButtonState_1;
  ButtonState_2 == LastButtonState_2;
  ButtonState_3 == LastButtonState_3;
  ButtonState_4 == LastButtonState_4;
}


void anphimbatki() { // buoc = 0

  if ((ButtonState_1 != LastButtonState_1) || (ButtonState_2 != LastButtonState_2) || (ButtonState_3 != LastButtonState_3) || (ButtonState_4 != LastButtonState_4)) {
    lcd.clear();
    if ((ButtonState_1 == HIGH) || (ButtonState_2 == HIGH) || (ButtonState_3 == HIGH) || (ButtonState_4 == HIGH)) {
      lcd.setCursor(1, 0);
      lcd.print("AN PHIM BAT KI");
      lcd.setCursor(2, 1);
      lcd.print("DE TIEP TUC");
      delay(500);
      travephim();
      buoc = 1;
    }
  }
}

void tieptuc() { // buoc = 1
  if ((ButtonState_1 != LastButtonState_1) || (ButtonState_2 != LastButtonState_2) || (ButtonState_3 != LastButtonState_3) || (ButtonState_4 != LastButtonState_4)) {
    lcd.clear();
    if ((ButtonState_1 == HIGH) || (ButtonState_2 == HIGH) || (ButtonState_3 == HIGH) || (ButtonState_4 == HIGH)) {
      buoc = 2;
      delay(500);
      travephim();
    }
  }
}


void chonloai() { // buoc = 2
  lcd.setCursor(0, 0);
  lcd.print("PHIM 1: DO AN");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 2: DO UONG");
  travephim();

  if ((ButtonState_1 != LastButtonState_1) || (ButtonState_2 != LastButtonState_2) || (ButtonState_3 != LastButtonState_3) || (ButtonState_4 != LastButtonState_4)) {
    lcd.clear();
    if (ButtonState_1 == HIGH) {
      travephim();
      buoc = 3;
    }

    else if (ButtonState_2 == HIGH) {
      travephim();
      buoc = 4;
    }
  }
}


void huongdanchondoan() { // buoc = 3
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DOC CHI DAN SAU:");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 1: LEN");
  delay(2350);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("PHIM 1: LEN");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 2: XUONG");
  delay(2350);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("PHIM 2: XUONG");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 3: CHON");
  delay(2350);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("PHIM 3: CHON");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 4: QUAY LAI");
  delay(2350);
  lcd.clear();

  buoc = 5;
  travephim();
}





void huongdanchondouong() { // buoc = 4

  lcd.setCursor(0, 0);
  lcd.print("DOC CHI DAN SAU:");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 1: LEN");
  delay(2350);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("PHIM 1: LEN");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 2: XUONG");
  delay(2350);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("PHIM 2: XUONG");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 3: CHON");
  delay(2350);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("PHIM 3: CHON");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 4: QUAY LAI");
  delay(2350);
  lcd.clear();

  buoc = 6;
  travephim();
}





void doan() { // buoc = 5

  switch (sttdoan) {
    case 0:
      sttdoan = 9;
      break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.print("1.MY RAMEN RAU");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 88.000 VND");
      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.print("2.MY RAMEN MISO");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 98.000 VND");
      break;

    case 3:
      lcd.setCursor(0, 0);
      lcd.print("3.MY SUI CAO HQ");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 88.000 VND");
      break;

    case 4:
      lcd.setCursor(0, 0);
      lcd.print("4.MY HOANH THANH");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 78.000 VND");
      break;

    case 5:
      lcd.setCursor(0, 0);
      lcd.print("5.MY SOT BO CAY");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 88.000 VND");
      break;

    case 6:
      lcd.setCursor(0, 0);
      lcd.print("6.MY UDON BO");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 88.000 VND");
      break;

    case 7:
      lcd.setCursor(0, 0);
      lcd.print("7.MY SOT TUONG");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 78.000 VND");
      break;

    case 8:
      lcd.setCursor(0, 0);
      lcd.print("8.MY TOM VIEN");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 78.000 VND");
      break;

    case 9:
      lcd.setCursor(0, 0);
      lcd.print("9.MY CA VIEN");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 78.000 VND");
      break;

    case 10:
      lcd.setCursor(0, 0);
      lcd.print("10.MY RAU CU");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 78.000 VND");
      break;

    case 11:
      lcd.setCursor(0, 0);
      lcd.print("11.MY XA XIU");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 78.000 VND");
      break;

    case 12:
      lcd.setCursor(0, 0);
      lcd.print("12.MY XAO XI DAU");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 88.000 VND");
      break;

    case 13:
      sttdoan = 1;
      break;
  }

  if ((ButtonState_1 != LastButtonState_1) || (ButtonState_2 != LastButtonState_2) || (ButtonState_3 != LastButtonState_3) || (ButtonState_4 != LastButtonState_4)) {
    if (ButtonState_1 == HIGH) {
      lcd.clear();
      sttdoan--;
      delay(300);
      travephim();
    }

    else if (ButtonState_2 == HIGH) {
      lcd.clear();
      sttdoan++;
      delay(300);
      travephim();
    }

    if (sttdoan == 0) {
      sttdoan = 12;
    }

    else if (ButtonState_3 == HIGH) {
      lcd.clear();
      if ((dachondoan == 0) && (dachondouong == 0)) {
        dachondoan = 1;
        delay(300);
        travephim();
        buoc = 7;
      }

      else if ((dachondouong == 1) && (dachondoan == 0)) {
        dachondoan = 2;
        delay(300);
        travephim();
        buoc = 7;
      }

    }

    else if (ButtonState_4 == HIGH) {
      lcd.clear();
      if ((dachondoan == 0) && (dachondouong == 0)) {
        delay(300);
        travephim();
        buoc = 2;
      }

      else if ((dachondouong == 1) && (dachondoan == 0)) {
        delay(300);
        travephim();
        buoc = 10;
      }
    }
  }
}



void douong() { // buoc = 6

  switch (sttdouong) {
    case 0:
      sttdouong = 11;
      break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.print("1.VANG DO SPEE");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 450.000 VND");
      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.print("2.VANG DO CARMEN");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 450.000 VND");
      break;

    case 3:
      lcd.setCursor(0, 0);
      lcd.print("3.VANG DO SIEGEL");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 780.000 VND");
      break;

    case 4:
      lcd.setCursor(0, 0);
      lcd.print("4.CA PHE DEN");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 33.000 VND");
      break;

    case 5:
      lcd.setCursor(0, 0);
      lcd.print("5.SUA DAU NANH");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 28.000 VND");
      break;

    case 6:
      lcd.setCursor(0, 0);
      lcd.print("6.BIA SAIGON 330");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 25.000 VND");
      break;

    case 7:
      lcd.setCursor(0, 0);
      lcd.print("7.BIA TIGER 330");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 27.000 VND");
      break;

    case 8:
      lcd.setCursor(0, 0);
      lcd.print("8.PEPSI 330ML");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 20.000 VND");
      break;

    case 9:
      lcd.setCursor(0, 0);
      lcd.print("9.7 UP");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 20.000 VND");
      break;

    case 10:
      lcd.setCursor(0, 0);
      lcd.print("10.TRA ANH QUOC");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 49.000 VND");
      break;

    case 11:
      lcd.setCursor(0, 0);
      lcd.print("11.TRA HOA CUC");
      lcd.setCursor(0, 1);
      lcd.print("GIA: 49.000 VND");
      break;

    case 12:
      sttdouong = 1;
      break;
  }

  if ((ButtonState_1 != LastButtonState_1) || (ButtonState_2 != LastButtonState_2) || (ButtonState_3 != LastButtonState_3) || (ButtonState_4 != LastButtonState_4)) {

    if (ButtonState_1 == HIGH) {
      lcd.clear();
      sttdouong--;
      delay(300);
      travephim();
    }

    else if (ButtonState_2 == HIGH) {
      lcd.clear();
      sttdouong++;
      delay(300);
      travephim();
    }

    else if (sttdouong == 0) {
      sttdouong = 11;
    }

    else if (ButtonState_3 == HIGH) {
      lcd.clear();
      if ((dachondoan == 0) && (dachondouong == 0)) {
        dachondouong = 1;
        delay(300);
        travephim();
        buoc = 7;
      }

      else if ((dachondoan == 1) && (dachondouong == 0)) {
        dachondouong = 2;
        delay(300);
        travephim();
        buoc = 7;
      }
    }

    else if (ButtonState_4 == HIGH) {
      lcd.clear();
      if ((dachondoan == 0) && (dachondouong == 0)) {
        delay(300);
        travephim();
        buoc = 2;
      }

      else if ((dachondoan == 1) && (dachondouong == 0)) {
        delay(300);
        travephim();
        buoc = 9;
      }

    }
  }
}


void huongdansoluong() { // buoc = 7

  lcd.setCursor(0, 0);
  lcd.print("DOC CHI DAN SAU:");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 1: -");
  delay(2350);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("PHIM 1: -");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 2: +");
  delay(2350);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("PHIM 2: +");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 3: CHON");
  delay(2350);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("PHIM 3: CHON");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 4: QUAY LAI");
  delay(2350);
  lcd.clear();

  buoc = 8;
  travephim();
}


void SoLuong() { // buoc = 8

  lcd.setCursor(4, 0);
  lcd.print("SO LUONG");

  switch (soluong) {
    case 0:
      soluong = 10;
      break;

    case 1:
      lcd.setCursor(0, 1);
      lcd.print("-      01      +");
      break;

    case 2:
      lcd.setCursor(0, 1);
      lcd.print("-      02      +");
      break;

    case 3:
      lcd.setCursor(0, 1);
      lcd.print("-      03      +");
      break;

    case 4:
      lcd.setCursor(0, 1);
      lcd.print("-      04      +");
      break;

    case 5:
      lcd.setCursor(0, 1);
      lcd.print("-      05      +");
      break;

    case 6:
      lcd.setCursor(0, 1);
      lcd.print("-      06      +");
      break;

    case 7:
      lcd.setCursor(0, 1);
      lcd.print("-      07      +");
      break;

    case 8:
      lcd.setCursor(0, 1);
      lcd.print("-      08      +");
      break;

    case 9:
      lcd.setCursor(0, 1);
      lcd.print("-      09      +");
      break;

    case 10:
      lcd.setCursor(0, 1);
      lcd.print("-      10      +");
      break;

    case 11:
      soluong = 1;
      break;
  }

  if ((ButtonState_1 != LastButtonState_1) || (ButtonState_2 != LastButtonState_2) || (ButtonState_3 != LastButtonState_3) || (ButtonState_4 != LastButtonState_4)) {
    lcd.clear();
    if (ButtonState_1 == HIGH) {
      soluong--;
      delay(300);
      travephim();
    }

    else if (ButtonState_2 == HIGH) {
      soluong++;
      delay(300);
      travephim();
    }

    else if (ButtonState_3 == HIGH) {
      if ((dachondoan == 1) && (dachondouong == 0))  {
        lcd.clear();
        delay(500);
        travephim;
        buoc = 9;
      }

      else if ((dachondouong == 1) && (dachondoan == 0)) {
        lcd.clear();
        delay(500);
        travephim;
        buoc = 10;
      }

      else if (((dachondoan == 1) && (dachondouong == 2)) || ((dachondoan == 2) && (dachondouong == 1))) {
        lcd.clear();
        delay(500);
        travephim;
        buoc = 11;
      }
    }

    else if (ButtonState_4 == HIGH) {
      lcd.clear();
      travephim;
      if ((dachondoan == 1) && (dachondouong == 0))  {
        delay(500);
        travephim;
        lcd.clear();
        dachondoan = 0;
        buoc = 5;
      }

      else if ((dachondoan == 0) && (dachondouong == 1)) {
        delay(500);
        travephim;
        lcd.clear();
        dachondouong = 0;
        buoc = 6;
      }

      else if ((dachondoan == 2) && (dachondouong == 1)) {
        delay(500);
        travephim;
        lcd.clear();
        buoc = 5;
        dachondoan = 0;
      }

      else if ((dachondoan == 1) && (dachondouong == 2)) {
        delay(500);
        travephim;
        lcd.clear();
        buoc = 6;
        dachondouong = 0;
      }

    }
  }
}


void chonthemdouong() { // buoc = 9
  lcd.setCursor(0, 0);
  lcd.print("PHIM 1:+ DO UONG");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 2: BO QUA");

  if ((ButtonState_1 != LastButtonState_1) || (ButtonState_2 != LastButtonState_2) || (ButtonState_3 != LastButtonState_3) || (ButtonState_4 != LastButtonState_4)) {
    lcd.clear();
    if (ButtonState_1 == HIGH) {
      lcd.clear();
      travephim();
      delay(500);
      buoc = 4;
    }

    else if (ButtonState_2 == HIGH) {
      lcd.clear();
      travephim();
      delay(500);
      buoc = 11;
    }
  }
}


void chonthemdoan() { // buoc = 10
  lcd.setCursor(0, 0);
  lcd.print("PHIM 1:+ DO AN");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 2: BO QUA");

  if ((ButtonState_1 != LastButtonState_1) || (ButtonState_2 != LastButtonState_2) || (ButtonState_3 != LastButtonState_3) || (ButtonState_4 != LastButtonState_4)) {
    lcd.clear();
    if (ButtonState_1 == HIGH) {
      lcd.clear();
      travephim();
      delay(300);
      buoc = 3;
    }

    else if (ButtonState_2 == HIGH) {
      lcd.clear();
      travephim();
      delay(300);
      buoc = 11;
    }
  }
}


void dangguidi() {
  lcd.setCursor(0, 0);
  lcd.print("DANG GUI DI ");

  lcd.setCursor(12, 0);
  lcd.print(".");
  delay(500);

  lcd.setCursor(13, 0);
  lcd.print(".");
  delay(500);

  lcd.setCursor(14, 0);
  lcd.print(".");
  delay(500);

  lcd.clear();

  lcd.setCursor(1, 0);
  lcd.print("GUI THANH CONG");
  delay(2500);
}


void chucngonmieng() {
  lcd.setCursor(1, 0);
  lcd.print("CHUC QUY KHACH");
  lcd.setCursor(2, 1);
  lcd.print("NGON MIENG !");
}

void thietlaplai() {
  digitalWrite(reset, LOW);
  digitalWrite(reset, HIGH);
}


void gui() { // buoc = 11
  lcd.setCursor(0, 0);
  lcd.print("PHIM 1: GUI DI");
  lcd.setCursor(0, 1);
  lcd.print("PHIM 2: QUAY LAI");
  travephim();


  if (ButtonState_1 == HIGH) {
    lcd.clear();
    travephim();
    digitalWrite(led, HIGH);

    lcd.clear();
    dangguidi();

    lcd.clear();
    chucngonmieng();
    delay(2500);

    digitalWrite(led, LOW);

    travephim();
    lcd.clear();
    thietlaplai();
  }

  else if (ButtonState_2 == HIGH) {
    lcd.clear();
    delay(500);
    travephim;
    if (dachondoan > dachondouong) {
      buoc = 5;
    }

    else if (dachondouong > dachondoan) {
      buoc = 6;
    }
  }
}


void loop() {

  Serial.println(millis());
  Serial.println(time);


  if ((ButtonState_1 != LastButtonState_1) || (ButtonState_2 != LastButtonState_2) || (ButtonState_3 != LastButtonState_3) || (ButtonState_4 != LastButtonState_4)) {
    if ((ButtonState_1 == HIGH) || (ButtonState_2 == HIGH) || (ButtonState_3 == HIGH) || (ButtonState_4 == HIGH)) {
      time = millis();
      travephim();
    }
  }

  else if (((ButtonState_1 == LastButtonState_1) && (ButtonState_2 == LastButtonState_2) && (ButtonState_3 == LastButtonState_3) && (ButtonState_4 == LastButtonState_4)) && (millis() - time > 30000)) {
    thietlaplai();
  }


  ButtonState_1 = digitalRead(button1);
  ButtonState_2 = digitalRead(button2);
  ButtonState_3 = digitalRead(button3);
  ButtonState_4 = digitalRead(button4);

  switch (buoc) {
    case 0:
      anphimbatki();
      break;

    case 1:
      tieptuc();
      break;

    case 2:
      chonloai();
      break;

    case 3:
      huongdanchondoan();
      break;

    case 4:
      huongdanchondouong();
      break;

    case 5:
      doan();
      break;

    case 6:
      douong();
      break;

    case 7:
      huongdansoluong();
      break;

    case 8:
      SoLuong();
      break;

    case 9:
      chonthemdouong();
      break;

    case 10:
      chonthemdoan();
      break;

    case 11:
      gui();
      break;

  }
}
