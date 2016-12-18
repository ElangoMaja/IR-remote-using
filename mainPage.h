const char MAIN_page[] PROGMEM = R"=====(
<HTML>
<head>
<script>
function startTime() {
    var today = new Date();
    var h = today.getHours();
    var m = today.getMinutes();
    var s = today.getSeconds();
    m = checkTime(m);
    s = checkTime(s);
    document.getElementById('txt').innerHTML =
    h + ":" + m + ":" + s;
    var t = setTimeout(startTime, 500);
}
function checkTime(i) {
    if (i < 10) {i = "0" + i};  
    return i;
}
</script>
</head>
<TITLE>
Z POWER
</TITLE>
<BODY>
<CENTER>
<FORM method="post" action="/form">
<TABLE>
<TR><TD colspan=2><B>Z POWER</B></TD></TR>
<TR><TD>IP Address: @@IP@@ </TD></TR>
<TR><TD>MAC Address: @@mac@@ </TD></TR>
<TR><TD>SIGNAL: @@Signal@@ % </TD></TR>
<TR><TD>Temp: @@TEMP@@ C</TD><TD>Load Status</TD></TR>

<TR><TD>
<INPUT TYPE=SUBMIT VALUE="ON1" name=submit>
<INPUT TYPE=SUBMIT VALUE="@@L1@@" name=submit>
</TD>
<TD>@@L1@@</TD></TR>

<TR><TD>
<INPUT TYPE=SUBMIT VALUE="ON2" name=submit>
<INPUT TYPE=SUBMIT VALUE="OFF2" name=submit>
</TD>
<TD>@@L2@@</TD></TR>

<TR><TD>
<INPUT TYPE=SUBMIT VALUE="ON3" name=submit>
<INPUT TYPE=SUBMIT VALUE="OFF3" name=submit>
</TD>
<TD>@@L3@@</TD></TR>

<TR><TD>
<INPUT TYPE=SUBMIT VALUE="ON4" name=submit>
<INPUT TYPE=SUBMIT VALUE="OFF4" name=submit>
</TD>
<TD>@@L4@@</TD></TR>

<TR><TD>
<INPUT TYPE=SUBMIT VALUE="Enable" name=submit>
<INPUT TYPE=SUBMIT VALUE="Disable" name=submit>
</TD>
<TD>@@L5@@</TD></TR>

</CENTER>
</BODY>
<body onload="startTime()">
<div id="txt"></div>
</body>
</HTML>
)=====";
