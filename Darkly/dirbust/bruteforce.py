import requests, sys

URL = sys.argv[1]
DICO = sys.argv[2]

req = requests.get(URL + "vhbdfsjvbdfsjbvksdfbvjlhsdblvsdflnv")
RESP = req.text;

with open(DICO, 'r') as fd:
    line = fd.readline()
    while line:
        req = requests.get(URL + line.rstrip('\n'))
        if req.text != RESP:
            print('FOUND {:50}code :{}'.format(URL + line.rstrip('\n'), req.status_code))
        try:
            line = fd.readline()
        except:
            line = 'error'
            print("error")
    fd.close()
