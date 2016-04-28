#afficher le résultat d'une seule simulation
sim=read.table("simulation.txt")
plot(sim$V1,sim$V2, col=sim$V3)

#diagramme de phase
diag = read.table("first_diagramme.txt")
plot(diag$V1,diag$V2,col=diag$V3,pch=20,main="Diagramme de phase",xlab="T",ylab="A",cex=1)
diag2 = read.table("diagramme.txt")
points(diag2$V1,diag2$V2,col=diag2$V3,pch=20,cex=1)
diag3 = read.table("passage3.txt")
points(diag3$V1,diag3$V2,col=diag3$V3,pch=20,cex=1)
diag4 = read.table("passage4.txt")
points(diag4$V1,diag4$V2,col=diag4$V3,pch=20,cex=1)
diag5 = read.table("passage5.txt")
points(diag5$V1,diag5$V2,col=diag5$V3,pch=20,cex=1)
diag6 = read.table("passage6.txt")
points(diag6$V1,diag6$V2,col=diag6$V3,pch=20,cex=1)
diag7 = read.table("passage7.txt")
points(diag7$V1,diag7$V2,col=diag7$V3,pch=20,cex=1)
diag8 = read.table("passage8.txt")
points(diag8$V1,diag8$V2,col=diag8$V3,pch=20,cex=1)
diag9 = read.table("passage9.txt")
points(diag9$V1,diag9$V2,col=diag9$V3,pch=20,cex=1)

#avec Pmut = 0.001
mut = read.table("mut.txt")
plot(mut$V1,mut$V2,col=mut$V3,pch=20,main="Diagramme de phase",xlab="T",ylab="A",cex=1)