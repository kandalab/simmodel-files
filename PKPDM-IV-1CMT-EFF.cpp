$PROB IV ONE COMP PKPD EFFECT COMPARTMENT MODEL

$PARAM @annotated
CL 		: 5   : Clearance (L/hr)
V1 		: 25  : Central Volume (L)


$OMEGA @annotated @block
ETA_CL      : 0.01 : ETA on CL
ETA_V1      : 0 0 0.01 : ETA on V1



$CMT @annotated
CENT    : Central (mass)


$MAIN
double CLi = CL * exp(ETA_CL);
double V1i = V1 * exp(ETA_V1);




$ODE
dxdt_CENT = - (CLi/V1i)*CENT;


$TABLE
double CENTRAL = CENT/V1i 


$CAPTURE @annotated
CENTRAL    : Plasma Concentration (mass/time UM)

  
