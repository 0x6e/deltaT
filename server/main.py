from ThermostatRequestHandler import *
import time
import http.server

HOST_NAME = ''
PORT_NUMBER = 80

if __name__ == '__main__':
    server_class = http.server.HTTPServer
    httpd = server_class((HOST_NAME, PORT_NUMBER), ThermostatRequestHandler)
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        pass
    httpd.server_close()

