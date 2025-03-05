texto="Testando..."
echo $texto
echo "$texto"
echo '$texto'
echo `$texto`
echo `$texto`
echo $texto $texto
comando=$(date)
echo $comando
echo "Hoje é: $comando"
echo "Hoje é: $(date)"
echo "Hoje é: `date`"
echo "Hoje é: $(date +%d-%m-%Y)"
echo este é um texto que ocupa \
> mais de uma linha
echo seu diretório atual: $(pwd)
