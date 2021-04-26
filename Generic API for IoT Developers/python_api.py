import urllib.request


class gvpIotApi:
    host = "https://parna-tech-gvp.000webhostapp.com"
    url = "/api/"
    rowCount = 0
    access = False
    table = list(list())

    def __init__(self):
    	try:
    	    urllib.request.urlopen(self.host, timeout=1)
    	    self.access = True
    	except urllib.error.HTTPError as err:
    	    self.access = False
		if self.access:
			print("have a internet and host")
		else:
			print("don't have a internet or host")

	def select(self, api, deviceID, w_data=None):
		if not self.access:
			print("don't have a internet or host")
			return f = ""
		if w_data is None:
    		f = urllib.request.urlopen(
    		    self.host+self.url+"select.php?api="+api+"&id="+deviceID)
    	else:
			f = urllib.request.urlopen(
			    self.host+self.url+"select.php?api="+api+"&id="+deviceID+"&w_data="+w_data)
		responce = str(f.read())
		data = responce.split('$')
		self.rowCount = int(data[1])
		data = data[2:len(data)-1]
		for i in data:
			self.table.append(i.split(","))

	def update(self, api, deviceID, data, w_data=None):
		if not self.access:
			print("don't have a internet or host")
			return f = ""
		if w_data is None:
			f = urllib.request.urlopen(
			    self.host+self.url+"update.php?api="+api+"&id="+deviceID+"&data="+data)
		else:
			f = urllib.request.urlopen(self.host+self.url+"update.php?api=" +
			                           api+"&id="+deviceID+"&data="+data+"&w_data="+w_data)
		responce = str(f.read())
		data = responce.split('$')
		return data[1]

	def insert(self, api, deviceID, data):
		if not self.access:
			print("don't have a internet or host")
		    return f = ""
		f = urllib.request.urlopen(self.host+self.url+"insert.php?api="+api+"&id="+deviceID+"&data="+data)
		responce = str(f.read())
		data = responce.split('$')
		return data[1]
