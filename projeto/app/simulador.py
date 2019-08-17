import requests

while(True):
    valor = int(input("Informe um valor: "))
    r = requests.post( "http://placarvirtual.herokuapp.com/upload" , json = {"LDR":valor} )
    print(r.status_code)

    r = requests.get( "http://placarvirtual.herokuapp.com/download" )
    print(r.json())
