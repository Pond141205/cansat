 const char Html_CS[]  = R"=====(

<!DOCTYPE html>
<html>
<head>
	<title>Stellar Strikers</title>
   <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>

	<style>
		body {
			background-color: #000000;
			font-family: Arial, sans-serif;
            color: #ffffff;
		}
		

        .RocketCard {
            position: absolute;
            width: 600px;
            height: 670px;
            top: 25%;
            background-color: #252729;
            border-radius: 1px;
            box-sizing: border-box;
            margin: 5px;
            padding: 10px;
            align-items: center;
        }

        .RocketCard h1 {
            display: block;
            color: #08ff00;
            text-align: center;
        }

        .RocketCard h2, h3 {
            display: block;
            color: #08ff00;
            text-align: left;
        }

        .RocketCard p {
            color: #d80ca5;
        }

        .CansatCard  {
            position: absolute;
            width: 600px;
            height: 670px;
            top: 25%;
            left: 33.6%;
            background-color: #252729;
            border-radius: 1px;
            box-sizing: border-box;
            margin: 5px;
            padding: 10px;
            align-items: center;
            
        }

        .CansatCard h1 {
            display: block;
            color: #08ff00;
            text-align: center;
        }

        .CansatCard h2, h3 {
            display: block;
            color: #08ff00;
            text-align: left;
        }

        .CansatCard p {
            color: #d80ca5;
        }


        .MissionCard  {
            position: absolute;
            width: 600px;
            height: 670px;
            top: 25%;
            left: 66.9%;
            background-color: #252729;
            border-radius: 1px;
            box-sizing: border-box;
            margin: 5px;
            padding: 10px;
            align-items: center;
            
        }

        .MissionCard h1 {
            display: block;
            color: #08ff00;
            text-align: center;
        }

        .MissionCard h2, h3 {
            display: block;
            color: #08ff00;
            text-align: left;
        }

        .MissionCard p {
            color: #d80ca5;
        }

        .titleCard {
            position: absolute;
            width: 300px;
            height: 150px;
            top: 10%;
            left: 50%;
            transform: translate(-50%, -50%);
            background-color: #000000;
            border-radius: 1px;
            box-sizing: border-box;
            margin: 5px;
            text-align: center;
        }

        .titleCard h1 {
            display: block;
            font-size: 2em;
            margin-block-start: 0.67em;
            margin-block-end: 0.67em;
            margin-inline-start: 0px;
            margin-inline-end: 0px;
            font-weight: bold;
        }

        .titleCard h2 {
            display: block;
            font-size: 1.5em;
            margin-block-start: 0.83em;
            margin-block-end: 0.83em;
            margin-inline-start: 0px;
            margin-inline-end: 0px;
            font-weight: bold;
        }




        .button {
            background-color: #000000; 
            border: 2px solid rgb(255, 255, 255);
            color: white;
            padding: 7px 15px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 16px;
            cursor: pointer;
        }

        .button1 {
            background-color: rgb(0, 0, 0); 
            color: white; 
        }

        .button1:hover {
            background-color: rgb(255, 255, 255);
            color: rgb(0, 0, 0);
        }
	</style>
</head>
<body>



    <div class="titleCard">
        <h1>PATHFINDER</h1>
        <h2>STELLAR STRIKERS</h2>
        <div style="font-size: 0.7rem;">
           <p> <span id="digital-clock">--:--:--</span></p>
           <div id="time">MT: 
             <span class="digit" id="hr">--</span>
             <span class="txt">:</span>
             <span class="digit" id="min">--</span>
             <span class="txt">:</span>
             <span class="digit" id="sec">--</span>
             <span class="txt">:</span>
             <span class="digit" id="count">--</span>
          </div>                 
        </div>
    </div>

    <div class="RocketCard">
        <h1>Rocket Status</h1>

        <p>RSSI: <span id="Rocket RSSI" style="color: #ffffff">--</span> dBm</p>
        <p>Reading ID: <span id="Rocket ReadingId"style="color: #ffffff">--</span></p>
        <p>Battery Voltage: <span id="Rocket Battery" style="color: #ffffff;">--</span> v</p>
        <p>Corrdinate: <span id="Rocket GPS" style="color: #ffffff">--</span></p>
        <p>Altitude: <span id="Rocket" style="color: #ffffff;">--</span> m</p>
        <p>Countdown: <span id="Rocket_Countdown" style="color: #ffffff;">--</span></p>
        <p>Deploy: <span id="Deploy_Rocket_State" style="color: #ffffff;">--</span></p>
    </div>

    <div class="CansatCard">
        <h1>Cansat Status</h1>

        <p>RSSI: <span id="RSSI" style="color: #ffffff;">--</span> dBm</p>
        <p>Reading Id: <span id="ReadingID" style="color: #ffffff;">--</span></p>
        <p>Battery Voltage: <span id="Cansat Battery" style="color: #ffffff;">--</span> v</p>
        <p>Corrdinate: <span id="CorrdinateVal" style="color: #ffffff;">--</span></p><br>

        <h3>Module Status</h3>
        <p>Module BME280: <span id="BME280_StatusVal" style="color: #ffffff;">--</span></p>
        <p>Module GY-1145: <span id="GY1145_StatusVal" style="color: #ffffff;">--</span></p>
        <p>Module MPU6050: <span id="MPU6050_StatusVal" style="color: #ffffff;">--</span></p><br>

        <h3>Servo Status</h3>
        <p>Servo1: <span id="Servo1_Status" style="color: #ffffff;">--</span></p>
        <p>Servo2: <span id="Servo2_Status" style="color: #ffffff;">--</span></p>
        <p>Servo3: <span id="Servo3_Status" style="color: #ffffff;">--</span></p>
        <p>Servo4: <span id="Servo4_Status" style="color: #ffffff;">--</span></p>
        <br> 
    </div>

    <div class="MissionCard">
        <h1>Mission Status</h1>

        <h3>Main Mission</h3>
        <p>Temperature: <span id="TempValue" style="color: #ffffff">--</span> &deg;C</p>
        <p>Pressure: <span id="PressValue" style="color: #ffffff;">--</span> hpa</p>
        <p>Humidity: <span id="HumiValue" style="color: #ffffff;">--</span> %</p>
        <p>Visible: <span id="VisValue" style="color: #ffffff;">--</span> mW/cm&#178;</p>
        <p>IR: <span id="IRValue" style="color: #ffffff;">--</span> mW/cm&#178;</p>
        <p>UV: <span id="UVindexValue" style="color: #ffffff;">--</span> mW/cm&#178;</p> 
        <p>Altitude: <span id="ALTValue" style="color: #ffffff;">--</span> m</p>
        <p>Acceleration: <span style="color: #ffffff" id="ACCValue">--</span> m/s</p><br>
        
        <h3>Side mission</h3>
        <p>Landing Gears: <span id="LandGear_Status" style="color: #ffffff;">--</span></p>
    </div>
    
    

 
	<script type ="text/javascript">
    setInterval(function(){
        getSensorVal();
        currentTime = getDateTime();
        document.getElementById("digital-clock").innerHTML = currentTime;
    }, 1000);

    function getSensorVal() {
        // Make AJAX request to fetch temperature data
        var TempValRequest = new XMLHttpRequest();
        TempValRequest.onreadystatechange = function()                            //Temperature
        {
            if (this.readyState == 4 && this.status == 200) 
            {
                document.getElementById("TempValue").innerHTML=this.responseText;
            }
        };
        TempValRequest.open("GET", "readTempVal", true);
        TempValRequest.send();

        var PressValRequest = new XMLHttpRequest();                              //Pressure
        PressValRequest.onreadystatechange = function()
        {
            if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("PressValue").innerHTML=this.responseText;
            }
        };
        PressValRequest.open("GET", "readPressVal", true);
        PressValRequest.send();

        var HumiValRequest = new XMLHttpRequest();                              //Humidity
        HumiValRequest.onreadystatechange = function()
        {
            if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("HumiValue").innerHTML=this.responseText;
            }
        };
        HumiValRequest.open("GET", "readHumiVal", true);
        HumiValRequest.send();
       
      
        var VisValRequest = new XMLHttpRequest();                              //Visible light
        VisValRequest.onreadystatechange = function()
        {
            if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("VisValue").innerHTML=this.responseText;
            }
        };
        VisValRequest.open("GET", "readVisVal", true);
        VisValRequest.send();

        var IRValRequest = new XMLHttpRequest();                               //IR
        IRValRequest.onreadystatechange = function()
        {
        if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("IRValue").innerHTML=this.responseText;
            }
        };
        IRValRequest.open("GET", "readIRVal", true);
        IRValRequest.send();

        var UVindexValRequest = new XMLHttpRequest();                         //UVindex
        UVindexValRequest.onreadystatechange = function()
        {
            if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("UVindexValue").innerHTML=this.responseText;
            }
        };
        UVindexValRequest.open("GET", "readUVindexVal", true);
        UVindexValRequest.send();

        var ALTValRequest = new XMLHttpRequest();                             // ALltitute
        ALTValRequest.onreadystatechange = function()
        {
            if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("ALTValue").innerHTML=this.responseText;
            }
        };
        ALTValRequest.open("GET", "readALTVal", true);
        ALTValRequest.send(); 

        var ACCValRequest = new XMLHttpRequest();                             // Acceleration
        ACCValRequest.onreadystatechange = function()
        {
            if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("ACCValue").innerHTML=this.responseText;
            }
        };
        ACCValRequest.open("GET", "readAcceVal", true);
        ACCValRequest.send(); 

        

        var RSSIValRequest = new XMLHttpRequest();                             // RSSI CANSAT
        RSSIValRequest.onreadystatechange = function()
        {
            if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("RSSI").innerHTML=this.responseText;
            }
        };
        RSSIValRequest.open("GET", "readRSSI", true);
        RSSIValRequest.send();

        var ReadingIDRequest = new XMLHttpRequest();                             // ReadingID 
        ReadingIDRequest.onreadystatechange = function()
        {
            if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("ReadingID").innerHTML=this.responseText;
            }
        };
        ReadingIDRequest.open("GET", "readReadingIDVal", true);
        ReadingIDRequest.send();

        var BMERequest = new XMLHttpRequest();                             // bme status
        BMERequest.onreadystatechange = function()
        {
            if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("BME280_StatusVal").innerHTML=this.responseText;
            }
        };
        BMERequest.open("GET", "readBME_Status", true);
        BMERequest.send();

        var GY1145Request = new XMLHttpRequest();                             // gy1145 status
        GY1145Request.onreadystatechange = function()
        {
            if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("GY1145_StatusVal").innerHTML=this.responseText;
            }
        };
        GY1145Request.open("GET", "readGY1145_Status", true);
        GY1145Request.send();

        var MPURequest = new XMLHttpRequest();                             // mpu6050 status
        MPURequest.onreadystatechange = function()
        {
            if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("MPU6050_StatusVal").innerHTML=this.responseText;
            }
        };
        MPURequest.open("GET", "readMPU6050_Status", true);
        MPURequest.send();

        var CorrdinateRequest = new XMLHttpRequest();                             // Corrdinate
        CorrdinateRequest.onreadystatechange = function()
        {
            if (this.readyState == 4 && this.status == 200)
            {
                document.getElementById("CorrdinateVal").innerHTML=this.responseText;
            }
        };
        CorrdinateRequest.open("GET", "readCorrdinateVal", true);
        CorrdinateRequest.send();



      }
  

      
             

        function getDateTime() {               //realtime date
            var now     = new Date(); 
            var year    = now.getFullYear();
            var month   = now.getMonth()+1; 
            var day     = now.getDate();
            var hour    = now.getHours();
            var minute  = now.getMinutes();
            var second  = now.getSeconds(); 
            if(month.toString().length == 1) {
                month = '0'+month;
            }
            if(day.toString().length == 1) {
                day = '0'+day;
            }   
            if(hour.toString().length == 1) {
                hour = '0'+hour;
            }
            if(minute.toString().length == 1) {
                minute = '0'+minute;
            }
            if(second.toString().length == 1) {
                second = '0'+second;
            }   
            var dateTime = year+'/'+month+'/'+day+' '+hour+':'+minute+':'+second;   
            return dateTime;
        }

        // example usage: realtime clock
        setInterval(function(){
            currentTime = getDateTime();
            document.getElementById("digital-clock").innerHTML = currentTime;
        }, 1000);

        
    

        let startBtn = document.getElementById('start');                        // Mission time
        let stopBtn = document.getElementById('stop');
        let resetBtn = document.getElementById('reset');

        let hour = 00;
        let minute = 00;
        let second = 00;
        let count = 00;
    
        startBtn.addEventListener('click', function () {
        timer = true;
        stopWatch();      
        });
  

  
        resetBtn.addEventListener('click', function () {
        timer = false;
        hour = 0;
        minute = 0;
        second = 0;
        count = 0;
        document.getElementById('hr').innerHTML = "00";
        document.getElementById('min').innerHTML = "00";
        document.getElementById('sec').innerHTML = "00";
        document.getElementById('count').innerHTML = "00";
        });
    
        function stopWatch() {
        if (timer) {
        count++;
    
        if (count == 100) {
        second++;
        count = 0;
        }
    
        if (second == 60) {
        minute++;
        second = 0;
        }
    
        if (minute == 60) {
        hour++;
        minute = 0;
        second = 0;
        }
    
        let hrString = hour;
        let minString = minute;
        let secString = second;
        let countString = count;
    
        if (hour < 10) {
        hrString = "0" + hrString;
        }
    
        if (minute < 10) {
        minString = "0" + minString;
        }
    
        if (second < 10) {
        secString = "0" + secString;
        }
    
        if (count < 10) {
        countString = "0" + countString;
        }
    
        document.getElementById('hr').innerHTML = hrString;
        document.getElementById('min').innerHTML = minString;
        document.getElementById('sec').innerHTML = secString;
        document.getElementById('count').innerHTML = countString;
        setTimeout(stopWatch, 10);
        }
      

        function startTimer(){
        timex = setTimeout(function(){
            seconds++;
        if(seconds >59){seconds=0;mins++;
            if(mins>59) {
            mins=0;hours++;
            if(hours <10) {$("#hours").text('0'+hours+':')} else $("#hours").text(hours+':');
            }
                        
        if(mins<10){                     
        $("#mins").text('0'+mins+':');}       
            else $("#mins").text(mins+':');
        }    
        if(seconds <10) {
        $("#seconds").text('0'+seconds);} else {
        $("#seconds").text(seconds);
        }
        
        
        startTimer();
        },1000);
        }
    }   

    

</script>
</body>
</html>

)=====";