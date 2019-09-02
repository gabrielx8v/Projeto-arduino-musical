#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

// comentários escritos por Gabriel Schnorrenberger.

// pinos do teclado:
// 1 pino = 28 2 pino = 27 3 pino = 26 4 pino = 25
// 5 pino = 24 6 pino = 23 7 pino = 28
// pinos de 1 a 4 = linhas do teclado de cima pra baixo.
// pinos de 5 a 7 = colunas do teclado da esquerda pra direita.

// arrays com pinos digitais do arduino na sequencia dos pinos do teclado.
int pinLinhas[] = {22, 23, 24, 25};
int pinColunas[] = {26, 27, 28};
const int buzzer = 11;

// array de chars representando cada tecla do teclado.
char teclas[4][3] = {{'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

void setup() {
  pinMode(buzzer, OUTPUT);
  // put your setup code here, to run once:

  // percorre toda lista de pinos das linhas.
  for (int numeroLinhas = 0; numeroLinhas < 4; numeroLinhas++) {
    // define o pino como saida.
    pinMode(pinLinhas[numeroLinhas], OUTPUT);
    // envia correte eletrica 5v para as saidas dos pinos.
    digitalWrite(pinLinhas[numeroLinhas], HIGH);
  }

  // percorre toda lista de pinos das colunas.
  for (int numeroColunas = 0; numeroColunas < 3; numeroColunas++) {
    // define o pino das colunas como entrada de pullup para verificar se recebeu corrente.
    pinMode(pinColunas[numeroColunas], INPUT_PULLUP); // o pullup significa que se não receber energia interpreta como ligado.
  }

  // inicia comunicação serial.
  Serial.begin(9600);
  // print inicial.
  Serial.print("teclado 4x3!");
  Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:

  // percorre novamente o array de linhas.
  for (int numeroLinhas = 0; numeroLinhas < 4; numeroLinhas++) {
    // desliga uma das linhas.
    digitalWrite(pinLinhas[numeroLinhas], LOW);


    //percorre o array de colunas.
    for (int numeroColunas = 0; numeroColunas < 3; numeroColunas++) {

      // verifica se a coluna referente a "numeroColunas" interpreta a entrada pullup como desligado
      // caso isso ocorra significa que o botão [numeroLinhas][numeroColunas] foi pressionado. e será executado o codigo dentro do if.
      if (digitalRead(pinColunas[numeroColunas]) == LOW) {
        // exibe a tecla pressionada no monitor serial.
        Serial.print("tecla: ");
        Serial.println(teclas[numeroLinhas][numeroColunas]);
        if (teclas[numeroLinhas][numeroColunas] == '1') {
          tone(buzzer, 783);
        }
        if (teclas[numeroLinhas][numeroColunas] == '2') {
          tone(buzzer, 880);
        }
        if (teclas[numeroLinhas][numeroColunas] == '3') {
          tone(buzzer, 987);
        }
        if (teclas[numeroLinhas][numeroColunas] == '4') {
          tone(buzzer, 1046);
        }
        if (teclas[numeroLinhas][numeroColunas] == '5') {
          tone(buzzer, 1174);
        }
        if (teclas[numeroLinhas][numeroColunas] == '6') {
          tone(buzzer, 1318);
        }
        if (teclas[numeroLinhas][numeroColunas] == '7') {
          tone(buzzer, 1396);
        }
        if (teclas[numeroLinhas][numeroColunas] == '8') {
          tone(buzzer, 1567);
        }
        if (teclas[numeroLinhas][numeroColunas] == '9') {
          tone(buzzer, 1760);
        }
        if (teclas[numeroLinhas][numeroColunas] == '*') {
          
          digitalWrite(pinLinhas[4], LOW);
          int tempo = 120;

          int melody[] = {

            // Pink Panther theme
            // Score available at https://musescore.com/benedictsong/the-pink-panther
            // Theme by Masato Nakamura, arranged by Teddy Mason

            REST, 2, REST, 4, REST, 8, NOTE_DS4, 8,
            NOTE_E4, -4, REST, 8, NOTE_FS4, 8, NOTE_G4, -4, REST, 8, NOTE_DS4, 8,
            NOTE_E4, -8, NOTE_FS4, 8,  NOTE_G4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_E4, 8, NOTE_G4, -8, NOTE_B4, 8,
            NOTE_AS4, 2, NOTE_A4, -16, NOTE_G4, -16, NOTE_E4, -16, NOTE_D4, -16,
            NOTE_E4, 2, REST, 4, REST, 8, NOTE_DS4, 4,

            NOTE_E4, -4, REST, 8, NOTE_FS4, 8, NOTE_G4, -4, REST, 8, NOTE_DS4, 8,
            NOTE_E4, -8, NOTE_FS4, 8,  NOTE_G4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_G4, 8, NOTE_B4, -8, NOTE_E5, 8,
            NOTE_DS5, 1,
            NOTE_D5, 2, REST, 4, REST, 8, NOTE_DS4, 8,
            NOTE_E4, -4, REST, 8, NOTE_FS4, 8, NOTE_G4, -4, REST, 8, NOTE_DS4, 8,
            NOTE_E4, -8, NOTE_FS4, 8,  NOTE_G4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_E4, 8, NOTE_G4, -8, NOTE_B4, 8,

            NOTE_AS4, 2, NOTE_A4, -16, NOTE_G4, -16, NOTE_E4, -16, NOTE_D4, -16,
            NOTE_E4, -4, REST, 4,
            REST, 4, NOTE_E5, -8, NOTE_D5, 8, NOTE_B4, -8, NOTE_A4, 8, NOTE_G4, -8, NOTE_E4, -8,
            NOTE_AS4, 16, NOTE_A4, -8, NOTE_AS4, 16, NOTE_A4, -8, NOTE_AS4, 16, NOTE_A4, -8, NOTE_AS4, 16, NOTE_A4, -8,
            NOTE_G4, -16, NOTE_E4, -16, NOTE_D4, -16, NOTE_E4, 16, NOTE_E4, 16, NOTE_E4, 2,

          };

          int notes = sizeof(melody) / sizeof(melody[0]) / 2;
          int wholenote = (60000 * 4) / tempo;
          int divider = 0, noteDuration = 0;

          for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
           
            // calculates the duration of each note
            divider = melody[thisNote + 1];
            if (divider > 0) {
              // regular note, just proceed
              noteDuration = (wholenote) / divider;
            } else if (divider < 0) {
              // dotted notes are represented with negative durations!!
              noteDuration = (wholenote) / abs(divider);
              noteDuration *= 1.5; // increases the duration in half for dotted notes
            }

            // we only play the note for 90% of the duration, leaving 10% as a pause
            tone(buzzer, melody[thisNote], noteDuration * 0.9);

            // Wait for the specief duration before playing the next note.
            delay(noteDuration);

            // stop the waveform generation before the next note.
            noTone(buzzer);
             if(digitalRead(pinColunas[0]) == LOW){
              break;
            }
          }
        }

        if (teclas[numeroLinhas][numeroColunas] == '#') {
          digitalWrite(pinLinhas[4], LOW);
          int tempo = 140;

          int melody[] = {

            // Happy Birthday
            // Score available at https://musescore.com/user/8221/scores/26906
            REST, 2,
            NOTE_C4, 4, NOTE_C4, 8,
            NOTE_D4, -4, NOTE_C4, -4, NOTE_F4, -4,
            NOTE_E4, -2, NOTE_C4, 4, NOTE_C4, 8,
            NOTE_D4, -4, NOTE_C4, -4, NOTE_G4, -4,
            NOTE_F4, -2, NOTE_C4, 4, NOTE_C4, 8,

            NOTE_C5, -4, NOTE_A4, -4, NOTE_F4, -4,
            NOTE_E4, -4, NOTE_D4, -4, NOTE_AS4, 4, NOTE_AS4, 8,
            NOTE_A4, -4, NOTE_F4, -4, NOTE_G4, -4,
            NOTE_F4, -2,

          };


          int notes = sizeof(melody) / sizeof(melody[0]) / 2;
          int wholenote = (60000 * 4) / tempo;
          int divider = 0, noteDuration = 0;

          for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

            // calculates the duration of each note
            divider = melody[thisNote + 1];
            if (divider > 0) {
              // regular note, just proceed
              noteDuration = (wholenote) / divider;
            } else if (divider < 0) {
              // dotted notes are represented with negative durations!!
              noteDuration = (wholenote) / abs(divider);
              noteDuration *= 1.5; // increases the duration in half for dotted notes
            }

            // we only play the note for 90% of the duration, leaving 10% as a pause
            tone(buzzer, melody[thisNote], noteDuration * 0.9);

            // Wait for the specief duration before playing the next note.
            delay(noteDuration);

            // stop the waveform generation before the next note.
            noTone(buzzer);
            if(digitalRead(pinColunas[2]) == LOW){
              break;
            }
          }
        }

        if (teclas[numeroLinhas][numeroColunas] == '0') {
          digitalWrite(pinLinhas[4], LOW);
//          if()
          int tempo = 114;

          int melody[] = {

            REST, 2,
            NOTE_E4, 4,  NOTE_E4, 4,  NOTE_F4, 4,  NOTE_G4, 4, //1
            NOTE_G4, 4,  NOTE_F4, 4,  NOTE_E4, 4,  NOTE_D4, 4,
            NOTE_C4, 4,  NOTE_C4, 4,  NOTE_D4, 4,  NOTE_E4, 4,
            NOTE_E4, -4, NOTE_D4, 8,  NOTE_D4, 2,

            NOTE_E4, 4,  NOTE_E4, 4,  NOTE_F4, 4,  NOTE_G4, 4, //4
            NOTE_G4, 4,  NOTE_F4, 4,  NOTE_E4, 4,  NOTE_D4, 4,
            NOTE_C4, 4,  NOTE_C4, 4,  NOTE_D4, 4,  NOTE_E4, 4,
            NOTE_D4, -4,  NOTE_C4, 8,  NOTE_C4, 2,

            NOTE_D4, 4,  NOTE_D4, 4,  NOTE_E4, 4,  NOTE_C4, 4, //8
            NOTE_D4, 4,  NOTE_E4, 8,  NOTE_F4, 8,  NOTE_E4, 4, NOTE_C4, 4,
            NOTE_D4, 4,  NOTE_E4, 8,  NOTE_F4, 8,  NOTE_E4, 4, NOTE_D4, 4,
            NOTE_C4, 4,  NOTE_D4, 4,  NOTE_G3, 2,

            NOTE_E4, 4,  NOTE_E4, 4,  NOTE_F4, 4,  NOTE_G4, 4, //12
            NOTE_G4, 4,  NOTE_F4, 4,  NOTE_E4, 4,  NOTE_D4, 4,
            NOTE_C4, 4,  NOTE_C4, 4,  NOTE_D4, 4,  NOTE_E4, 4,
            NOTE_D4, -4,  NOTE_C4, 8,  NOTE_C4, 2

          };

          int notes = sizeof(melody) / sizeof(melody[0]) / 2;

          // this calculates the duration of a whole note in ms (60s/tempo)*4 beats
          int wholenote = (60000 * 4) / tempo;

          int divider = 0, noteDuration = 0;

          for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

            // calculates the duration of each note
            divider = melody[thisNote + 1];
            if (divider > 0) {
              // regular note, just proceed
              noteDuration = (wholenote) / divider;
            } else if (divider < 0) {
              // dotted notes are represented with negative durations!!
              noteDuration = (wholenote) / abs(divider);
              noteDuration *= 1.5; // increases the duration in half for dotted notes
            }

            // we only play the note for 90% of the duration, leaving 10% as a pause
            tone(buzzer, melody[thisNote], noteDuration * 0.9);

            // Wait for the specief duration before playing the next note.
            delay(noteDuration);

            // stop the waveform generation before the next note.
            noTone(buzzer);
            if(digitalRead(pinColunas[1]) == LOW){
              break;
            }
          }
        }

        // esta repetição serve para impedir que seja identificado varios click invés de 1.
        while (digitalRead(pinColunas[numeroColunas]) == LOW) {
        }
        noTone(buzzer);

      }
    }

    // religa a porta inicialmente desligada para que a proxima passe pelo mesmo processo.
    digitalWrite(pinLinhas[numeroLinhas], HIGH);
  }

  delay(10);
}
