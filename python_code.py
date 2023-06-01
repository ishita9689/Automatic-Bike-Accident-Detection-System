import serial
import yagmail
import geocoder
from datetime import datetime
import pywhatkit

g=geocoder.ip('me')
s=serial.Serial('COM5',9600,timeout=1)
receiver = "patilyashashree9689@gmail.com"
body = "hi, i have met with an an accident at coordinates : "+str(g.latlng)+" please contact the authorities"
yag = yagmail.SMTP("devops9689@gmail.com")
now = datetime.now()
current_time = now.strftime("%H:%M")
list1=current_time.split(':')

while 1:
    val=s.readline()
    s2=val.decode()
    
    if s2=="111\r\n":
        print("Accident Occured")
        pywhatkit.sendwhatmsg('+917219846196',"hi, i have met with an an accident at coordinates : "+str(g.latlng)+" please contact the authorities",int(list1[0]),int(list1[1])+1)
        yag.send(
            to=receiver,
            subject="ACCIDENT ALERT!!!",
            contents=body,
        )
        
        break
    