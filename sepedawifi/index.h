//---------------------------------------------------------------
//HTML CODE
static const char MAIN_PAGE[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
<center>
<h1>WiFi on off</h1><br>
<a href="ledOn1" target="myIframe">Lampu 1 ON</a><br>
<br>
<br>
<a href="ledOff1" target="myIframe">Lampu 1 OFF</a><br>
<br>
<a href="ledOn2" target="myIframe2">Lampu 2 ON</a><br>
<br>
<br>
<a href="ledOff2" target="myIframe2">Lampu 2 OFF</a><br>
<br>
<iframe name="myIframe" width="25%" height="25px" frameBorder="1"><br></iframe>
<iframe name="myIframe2" width="25%" height="25px" frameBorder="1"><br></iframe>
</center>

</body>
</html>
)=====";
//---------------------------------------------------------------
