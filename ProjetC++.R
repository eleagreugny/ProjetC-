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

d = read.table("sansmut.txt")
plot(d$V1,d$V2,col=d$V3,pch=20,main="Diagramme de phase avec Pmut = 0 et D = 0.1",xlab="T",ylab="A",cex=1)
legend("topright",legend=c("exclusion","cohabitation","exctinction"),col=c(3,2,1),pch = c(20,20,20))

#avec Pmut = 0.001
mut = read.table("mut.txt")
plot(mut$V1,mut$V2,col=mut$V3,pch=20,main="Diagramme de phase",xlab="T",ylab="A",cex=1)

mut2 = read.table("mut2.txt")
plot(mut2$V1,mut2$V2,col=mut2$V3,pch=20,main="Diagramme de phase avec Pmut = 0.001",xlab="T",ylab="A",cex=1)
legend("topleft",legend=c("exclusion","cohabitation","exctinction"),col=c(3,2,1),pch = c(20,20,20))

#variation de D
D0 = read.table("sansmutD0.txt")
plot(D0$V1,D0$V2,col=D0$V3,pch=20,main="Diagramme de phase avec D = 0",xlab="T",ylab="A",cex=1)
legend("topright",legend=c("exclusion","cohabitation","exctinction"),col=c(3,2,1),pch = c(20,20,20))

D01 = read.table("sansmutD01.txt")
plot(D01$V1,D01$V2,col=D01$V3,pch=20,main="Diagramme de phase avec D = 0.01",xlab="T",ylab="A",cex=1)
legend("top",legend=c("exclusion","cohabitation","exctinction"),col=c(3,2,1),pch = c(20,20,20))

D05 = read.table("sansmutD05.txt")
plot(D05$V1,D05$V2,col=D05$V3,pch=20,main="Diagramme de phase avec D = 0.05",xlab="T",ylab="A",cex=1)
legend("topright",legend=c("exclusion","cohabitation","exctinction"),col=c(3,2,1),pch = c(20,20,20))

D08 = read.table("sansmutD08.txt")
plot(D08$V1,D08$V2,col=D08$V3,pch=20,main="Diagramme de phase avec D = 0.08",xlab="T",ylab="A",cex=1)
legend("topright",legend=c("exclusion","cohabitation","exctinction"),col=c(3,2,1),pch = c(20,20,20))

D02 = read.table("sansmutD02.txt")
plot(D02$V1,D02$V2,col=D02$V3,pch=20,main="Diagramme de phase avec D = 0.02",xlab="T",ylab="A",cex=1)
legend("topright",legend=c("exclusion","cohabitation","exctinction"),col=c(3,2,1),pch = c(20,20,20))

D03 = read.table("sansmutD03.txt")
plot(D03$V1,D03$V2,col=D03$V3,pch=20,main="Diagramme de phase avec D = 0.03",xlab="T",ylab="A",cex=1)
legend("topright",legend=c("exclusion","cohabitation","exctinction"),col=c(3,2,1),pch = c(20,20,20))

D04 = read.table("sansmutD04.txt")
plot(D04$V1,D04$V2,col=D04$V3,pch=20,main="Diagramme de phase avec D = 0.04",xlab="T",ylab="A",cex=1)
legend("topright",legend=c("exclusion","cohabitation","exctinction"),col=c(3,2,1),pch = c(20,20,20))

D06 = read.table("sansmutD06.txt")
plot(D06$V1,D06$V2,col=D06$V3,pch=20,main="Diagramme de phase avec D = 0.06",xlab="T",ylab="A",cex=1)
legend("topright",legend=c("exclusion","cohabitation","exctinction"),col=c(3,2,1),pch = c(20,20,20))

D07 = read.table("sansmutD07.txt")
plot(D07$V1,D07$V2,col=D07$V3,pch=20,main="Diagramme de phase avec D = 0.07",xlab="T",ylab="A",cex=1)
legend("topright",legend=c("exclusion","cohabitation","exctinction"),col=c(3,2,1),pch = c(20,20,20))

D09 = read.table("sansmutD09.txt")
plot(D09$V1,D09$V2,col=D09$V3,pch=20,main="Diagramme de phase avec D = 0.09",xlab="T",ylab="A",cex=1)
legend("topright",legend=c("exclusion","cohabitation","exctinction"),col=c(3,2,1),pch = c(20,20,20))

#exam
t = read.table("test.txt")
plot(t$V1,t$V2,col=t$V3,pch=20,main="Diagramme de phase",xlab="T",ylab="A",cex=1)
