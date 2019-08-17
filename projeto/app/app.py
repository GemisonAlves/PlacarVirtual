import json

from flask import Flask, render_template, redirect, request
from flask_socketio import SocketIO, send, emit
from flask_cors import CORS  

app = Flask(__name__)
socketio = SocketIO(app)
CORS(app)

estado = {
    "LED01" : 0,
    "LED02" : 0
}
    


@app.route("/")
def rota_inicial():
    return render_template("index.html")

@app.route("/upload", methods=["POST"])
def rota_upload():
    mensagem = request.get_json()
    socketio.emit("atualiza", mensagem)
    return "200"
   
@app.route("/download", methods=['GET'])
def rota_download():
    global estado
    return json.dumps(estado)

@socketio.on("ligarLed")
def ligar_led():
    global estado
    estado["LED01"] = 1

@socketio.on("desligarLed")
def desligar_led():
    global estado
    estado["LED01"] = 0



if __name__ == "__main__":
    app.run("0.0.0.0",port=8080)