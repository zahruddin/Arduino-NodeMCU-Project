//---------------------------------------------------------------
//HTML CODE
static const char MAIN_PAGE[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style type="text/css">
  .btnON{
      background-color: #4CAF50; /* Green */
      border: none;
      border-radius: 12px;
      color: white;
      padding: 10px 25px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      font-size: 16px;
  }
  .btnOFF{
      background-color: #f44336; /* Green */
      border: none;
      border-radius: 12px;
      color: white;
      padding: 10px 25px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      font-size: 16px;
  }
  .btnSTART{
      background-color: #008CBA; /* Green */
      border: none;
      border-radius: 12px;
      color: white;
      padding: 10px 25px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      font-size: 16px;
  }
</style>
<body>
<center>
<h1>ASTREA LEGENDA</h1><br>
<a href="kuncion" target="myIframe" ><button type="button" class="btnON">KUNCI ON</button></a>
<a href="kuncioff" target="myIframe"><button type="button" class="btnOFF">KUNCI OFF</button></a><br>
<br>
<a href="start" target="myIframe2"><button type="button" class="btnSTART">START</button></a><br>
<br>
<iframe name="myIframe" style="display: none;" width="25%" height="25px" frameBorder="1"><br></iframe>
<iframe name="myIframe2" style="display: none;" width="25%" height="25px" frameBorder="1"><br></iframe>
</center>
</body>
</html>
)=====";
//---------------------------------------------------------------
