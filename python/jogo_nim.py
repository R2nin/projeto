import re
 
def le_assinatura():
    print("Bem-vindo ao detector automático de COH-PIAH.")
 
    wal = float(input("Entre o tamanho medio de palavra:"))
    ttr = float(input("Entre a relação Type-Token:"))
    hlr = float(input("Entre a Razão Hapax Legomana:"))
    sal = float(input("Entre o tamanho médio de sentença:"))
    sac = float(input("Entre a complexidade média da sentença:"))
    pal = float(input("Entre o tamanho medio de frase:"))
 
    return [wal, ttr, hlr, sal, sac, pal]
 
def le_texto():
    i = 1
    textos = []
    texto = input("Digite o texto " + str(i) +" (aperte enter para sair):")
    while texto:
        textos.append(texto)
        i += 1
        texto = input("Digite o texto " + str(i) +" (aperte enter para sair):")
 
    return textos
 
def separa_sentenca(texto):
  '''A funcao recebe um texto e retorna uma lista das sentencas dentro do texto'''
    sentencas = re.split(r'[.!?]+', texto)
    if sentencas[-1] == '':
        del sentencas[-1]
    return sentencas
 
def separa_frase(sentenca):
  '''A funcao recebe uma sentenca e retorna uma lista das frases dentro do texto'''
    return re.split(r'[,:;]+', sentenca)
 
 
def n_palavras_unicas(lista_palavras):
  '''Essa funcao recebe uma lista de palavras e retorna o numero de palavras que aparecem uma unica vez'''
    freq = dict()
    unicas = 0
    for palavra in lista_palavras:
        p = palavra.lower()
        if p in freq:
            if freq[p] == 1:
                unicas -= 1
            freq[p] += 1
        else:
            freq[p] = 1
            unicas += 1
 
    return unicas
 
def n_palavras_diferentes(lista_palavras):
  '''Essa funcao recebe uma lista de palavras e retorna o numero de palavras diferentes utilizadas'''
    freq = dict()
    for palavra in lista_palavras:
        p = palavra.lower()
        if p in freq:
            freq[p] += 1
        else:
            freq[p] = 1
 
    return len(freq)
 
def compara_assinatura(as_a, as_b):
    '''IMPLEMENTAR. Essa funcao recebe duas assinaturas de texto e 
    deve retornar o grau de similaridade nas assinaturas.'''
    pass
 
def calcula_assinatura(texto):
    '''IMPLEMENTAR. Essa funcao recebe um texto e 
    deve retornar a assinatura do texto.'''
    pass
 
def avalia_textos(textos, ass_cp):
    lista_assinatura = []
    for texto in textos:
        TamanhoMedioDePalavra = ?
        RelacaoTypeToken = ?
        RelacaoHapaxLegomana = ?
        TamanhoMedioDeSentenca = ?
        ComplexidadeMediaDeSentenca = ?
        TamanhoMedioDeFrase = ?
        lista_assinatura.append([TamanhoMedioDePalavra, RelacaoTypeToken, RelacaoHapaxLegomana, TamanhoMedioDeSentenca, ComplexidadeMediaDeSentenca, TamanhoMedioDeFrase])
    for assinatura in lista_assinatura:
 
 
 
    '''IMPLEMENTAR. Essa funcao recebe uma lista de textos e 
    deve retornar o numero (0 a n-1) do texto com maior 
    probabilidade de ter sido infectado por COH-PIAH.'''
    pass
ass_cp = le_assinatura()
 
textos = le_texto()
 
n = avalia_textos(textos, ass_cp)
 
print("O autor do texto", n + 1, "esta infectado com COH-PIAH")
