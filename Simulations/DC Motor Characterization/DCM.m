R=2.8;
L=0.0017342;
J=0.0000001343;
b=0.1;
Ke=0.6429;
Kt=0.6341;
K=0.5143;

syms s;
tA=1;
tB=(R*J+b*L)/(L*J);
tC=(R*b+Ke*Kt)/(L*J);
tD=Kt/(L*J);
tG=2.376;

T1=tG*tf([tD], [tA tB tC])
C
zpk(C)
T2=(T1*C)/(1+(T1*C))
zpk(T2)