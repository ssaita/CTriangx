//
//  paramt.h
//  Triangx
//
//  Created by Satoko Saita on 2017/08/22.
//  Copyright © 2017年 Satoko Saita. All rights reserved.
//

//二重インクルードの防止
#ifndef paramt_h
#define paramt_h
//     face
extern int iprf;
//     devision order
extern int iprm1,iprm2,iprm3,iprm4,iprm5,iprm6,iprm7;
extern int iprn2,iprn3,iprn4,iprn5,iprn6,iprn7;
extern int ipro;
extern int iprv;
extern int ipru;
//     altitude and variables
extern int iprz;
extern int ipri;
extern int iprc;

// triangx.f(main),filioz.f(dread0)
extern int nfc,norder,nv,nu,nz;
extern float deca;
///extern float r(iprz),rc(iprz),deca
extern double pi;
#endif /* paramt_h */

