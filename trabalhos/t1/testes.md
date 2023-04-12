# Teste 1:
### Entrada
- Numero de passagens: 1
- Destino: Litoral (1)
- Inclui seguro: Nao
- Inclui ida e volta: Nao

### Saída
- Valor base da compra: 1 * 216.72 = 216.72

- Valor do desconto: 0.0
- Valor da compra c/ desconto: 216.72

- Valor do seguro: 0.0
- Valor da compra c/ seguro: 216.72

- Valor final da compra: 216.72
- Percentual de diferenca: 0%

- Pontos: 1

# Teste 2
### Entrada
- Numero de passagens: 2
- Destino: Capital (2)
- Inclui seguro: Sim
- Inclui ida e volta: Nao

### Saída
- Valor base da compra: 2 * 157.36 = 314.72

- Valor do desconto: 9% * 157.36 = 14.1624
- Valor da compra c/ desconto: (314.72 - 14.1624) = 300.5576

- Valor do seguro: 2 * (2.16 / 100 * 157.36) = 6.797952
- Valor da compra c/ seguro: (300.5576 + 6.797952) = 307.355552

- Valor final da compra: 307.355552
- Percentual de diferenca: (307.355552 - 314.72) / 314.72 = -0.0234 = -2.34%

- Pontos: 2

# Teste 3
### Entrada
- Numero de passagens: 3
- Destino: Serra (3)
- Inclui seguro: Sim
- Inclui ida e volta: Nao

### Saída
- Valor base da compra: 3 * 182.19 = 546.57

- Valor do desconto: 182.19 * 11 / 100 + 182.19 * 13 / 100 = 43.7256
- Valor da compra c/ desconto: 546.57 - 43.7256 = 502.8444

- Valor do seguro: 3 * (182.19 * 2.16 / 100) = 11.805912
- Valor da compra c/ seguro: (502.8444 + 11.805912) = 514.650312

- Valor final da compra: 514.650312
- Percentual de diferenca: (514.650312 - 546.57) / 546.57 = -0.0584 = -5.84%

- Pontos: 4

# Teste 4
### Entrada
- Numero de passagens: 4
- Destino: Fronteira (4)
- Inclui seguro: Nao
- Inclui ida e volta: Nao

### Saída
- Valor base da compra: 4 * 259.41 = 1037.64

- Valor do desconto: (3 * 259.41) * 15 / 100 = 116.7345
- Valor da compra c/ desconto: (1037.64 - 116.7345) = 920.9055

- Valor do seguro: 0.0
- Valor da compra c/ seguro: 920.9055

- Valor final da compra: 920.9055
- Percentual de diferenca: (920.9055 - 1037.64) / 1037.64 = 0.1125 = -11.25%

- Pontos: 7

# Teste 5
### Entrada
- Numero de passagens: 5
- Destino: Interestadual (5)
- Inclui seguro: Sim
- Inclui ida e volta: Nao

### Saída
- Valor base da compra: 5 * 368.92 = 1844.6

- Valor do desconto: 1844.6 * 16 / 100 = 295.136
- Valor da compra c/ desconto: (1844.6 - 295.136) = 1549.464

- Valor do seguro: 5 * (368.92 * 2.16 / 100) = 39.84336
- Valor da compra c/ seguro: (1549.464 + 39.84336) = 1589.30736

- Valor final da compra: 1589.30736
- Percentual de diferenca: (1589.30736 - 1844.6) / 1844.6 = -0.1384 = -13.84%

- Pontos: 13.244228

# Teste 6
### Entrada
- Numero de passagens: 42
- Destino: Capital (2)
- Inclui seguro: Sim
- Inclui ida e volta: Sim

### Saída
- Valor base da compra: 42 * 157.36 = 6609.12

- Valor do desconto: 6609.12 * 16 / 100 = 1057.4592
- Valor da compra c/ desconto: (6609.12 - 1057.4592) = 5551.6608

- Valor do seguro: 42 * (157.36 * 2.16 / 100) = 142.756992
- Valor da compra c/ seguro: (5551.6608 + 142.756992) = 5694.417792

- Valor final da compra: 2 * 5694.417792 + 42 * 1.5 = 11451.835584
- Percentual de diferenca: (11451.835584 - 6609.12) / 6609.12 = 0.7327322826639554 = 73.27322826639554%

- Pontos: 95

# Teste 7
### Entrada
- Numero de passagens: 2531
- Destino: Interestadual (5)
- Inclui seguro: Nao
- Inclui ida e volta: Sim

### Saída
- Valor base da compra: 2531 * 368.92 = 933736.52

- Valor do desconto: 933736.52 * 16 / 100 = 149397.8432
- Valor da compra c/ desconto: (933736.52 - 149397.8432) = 784338.6768

- Valor do seguro: 0.0
- Valor da compra c/ seguro: 784338.6768

- Valor final da compra: 2 * 784338.6768 + 1.5 * 2531 = 1572473.8536
- Percentual de diferenca: (1572473.8536 - 933736.52) / 933736.52 = 0.6840659221511439 = 68.40659221511439%

- Pontos: 13103
