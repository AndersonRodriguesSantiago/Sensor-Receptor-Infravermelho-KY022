const int SenInfra = 5;
int cont = 0; // Variavel que que libera qual if o botão vai receber


void receptor()
{

  if (digitalRead(SenInfra) == LOW)//verifica se apertaram o botão do controle
  {
    //o robô inicia desligado com cont = 0;
    //o primeiro aperto do botão sempre será de ligá-lo;


    cont = cont + 1;
    delay(200);//precisa de delay para o sensor não receber mais de um sinal


    if (cont % 2 != 0) // se o valor do cont for irmpar o robô entra em modo de espera
    {
      Serial.println("modo de espera");
    }
    if (cont % 2 == 0) // se o valor do cont for par o robô entra em modo de ataque
    {
      Serial.println("modo de ataque");
    }
  }
}

void setup() {

  pinMode (SenInfra, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  receptor();
}
