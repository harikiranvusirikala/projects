#include <ESP8266WiFi.h>

class gvpIotApi
{
public:
	String ssid = "", password = "", host = "parna-tech-gvp.000webhostapp.com", url = "/api/";

public:
	WiFiClient client;

public:
	int rowCount = 0;

	gvpIotApi(String ssid, String password)
	{
		this->ssid = ssid;
		this->password = password;
		Serial.begin(115200);
		delay(20);
		Serial.print("Connecting to ");
		Serial.println(ssid);
		WiFi.begin(ssid, password);
		while (WiFi.status() != WL_CONNECTED)
		{
			delay(500);
			Serial.print(".");
		}
		Serial.println("");
		Serial.println("WiFi connected");

		Serial.println("IP address: ");
		Serial.println(WiFi.localIP());
	}

public:
	void select(String api, String deviceID, String w_data = "")
	{
		String url_temp = "";
		Serial.print("connecting to ");
		Serial.println(host);
		if (!client.connect(host, 80))
		{
			Serial.println("connection failed");
			return;
		}
		if (w_data.equals(""))
		{
			url_temp = url + "select.php?api=" + api + "&id=" + deviceID;
		}
		else
		{
			url_temp = url + "select.php?api=" + api + "&id=" + deviceID + "&w_data=" + w_data;
		}
		Serial.print("Requesting URL: ");
		Serial.println(url);
		client.print(String("GET ") + url_temp + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
		unsigned long timeout = millis();
		while (client.available() == 0)
		{
			if (millis() - timeout > 5000)
			{
				Serial.println(">>> Client Timeout !");
				client.stop();
				return;
			}
		}
		String line = "";
		if (client.available())
			line = client.readStringUntil('$');
		if (client.available())
			line = client.readStringUntil('$');
		rowCount = line.toInt() + 1;
		/*int c=0;
        while(client.available()){
            String line = client.readStringUntil('$'); 
        	if(c>=1)
            {
                Serial.println(line); 
            }
            c++;
        }*/
	}

public:
	String getNextLine()
	{
		if (client.available())
		{
			String line = client.readStringUntil('$');
			return line;
		}
		return "";
	}

public:
	int update(String api, String deviceID, String data, String w_data = "")
	{
		String url_temp = "";
		Serial.print("connecting to ");
		Serial.println(host);
		if (!client.connect(host, 80))
		{
			Serial.println("connection failed");
			return -1;
		}
		if (w_data.equals(""))
		{
			url_temp = url + "update.php?api=" + api + "&id=" + deviceID + "&data=" + data;
		}
		else
		{
			url_temp = url + "update.php?api=" + api + "&id=" + deviceID + "&data=" + data + "&w_data=" + w_data;
		}
		Serial.print("Requesting URL: ");
		Serial.println(url);
		client.print(String("GET ") + url_temp + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
		unsigned long timeout = millis();
		while (client.available() == 0)
		{
			if (millis() - timeout > 5000)
			{
				Serial.println(">>> Client Timeout !");
				client.stop();
				return -2;
			}
		}
		String line = "";
		if (client.available())
			line = client.readStringUntil('$');
		if (client.available())
			line = client.readStringUntil('$');
		int status = line.toInt();
		return status;
	}

public:
	int insert(String api, String deviceID, String data)
	{
		String url_temp = "";
		Serial.print("connecting to ");
		Serial.println(host);
		if (!client.connect(host, 80))
		{
			Serial.println("connection failed");
			return -1;
		}
		url_temp = url + "insert.php?api=" + api + "&id=" + deviceID + "&data=" + data;
		Serial.print("Requesting URL: ");
		Serial.println(url);
		client.print(String("GET ") + url_temp + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
		unsigned long timeout = millis();
		while (client.available() == 0)
		{
			if (millis() - timeout > 5000)
			{
				Serial.println(">>> Client Timeout !");
				client.stop();
				return -2;
			}
		}
		String line = "";
		if (client.available())
			line = client.readStringUntil('$');
		if (client.available())
			line = client.readStringUntil('$');
		int status = line.toInt();
		return status;
	}
}