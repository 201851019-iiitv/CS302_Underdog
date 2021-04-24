library(mclust)           # load mclust library
data = read.table("Desktop/week6/2020_em_clustering.csv",sep = ',')
a = vector()
for (i in data){
  a = c(a, i)
}
model <- Mclust(a,G=2 )
summary(model)
plot(model, what= "classification")