import http.server

class ThermostatRequestHandler(http.server.BaseHTTPRequestHandler):
	def do_HEAD(s):
		s.send_response(200)
		s.send_header("Content-type", "text/html")
		s.end_headers()

	def do_GET(s):
		s.send_response(200)
		s.send_header("Content-type", "text/html")
		s.end_headers()

		s.wfile.write(bytes("<html><head><title>Hello RequestHandler</title><head>", 'UTF-8'))
		s.wfile.write(bytes("<body><p>This is a test</p>", 'UTF-8'))
		s.wfile.write(bytes("<p>You accessed path: %s</p>" % s.path, 'UTF-8'))
		s.wfile.write(bytes("</body></html>", 'UTF-8'))

