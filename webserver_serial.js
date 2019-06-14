const SerialPort = require('serialport');
var express = require('express');
var path = require('path');
var app = express();
var portNumber = 3000;
var server = app.listen(portNumber, function () {
  console.log('App listening on port '+portNumber+'!');
});
var io = require('socket.io').listen(server);

const port = new SerialPort('COM3', { baudRate: 9600 });
//READLINE
const Readline = require('@serialport/parser-readline');
const parser = port.pipe(new Readline({ delimiter: '\n' }));

//SET PUBLIC
app.use(express.static('public'));

//GET DIRECTORY
app.get('/', function (req, res) {
  res.sendFile(path.join(__dirname+'/public/index.html'));
});

// Read the port data SERIAL
port.on("open", () => {
  console.log('serial port open');
});

parser.on('data', data => {
  console.log(':::::>>>arduino:', data);
});

//INIT IO CONECTION
io.on('connection', function(socket) {
  //SOCKET IO DIRECTION
  socket.on('direction', function(data) {
    console.log(data.direction);
    //SET DATA TO SERIAL PORT
    port.write(data.direction, (err) => {
		if (err) {
		  return console.log('Error on write: ', err.message);
		}
		console.log('message written');
	});
  });
});

