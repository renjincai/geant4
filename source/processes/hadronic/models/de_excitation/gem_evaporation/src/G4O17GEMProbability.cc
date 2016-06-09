//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: G4O17GEMProbability.cc,v 1.2 2003/11/03 17:53:04 hpw Exp $
// GEANT4 tag $Name: geant4-06-00 $
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara (Nov 1999)
//


#include "G4O17GEMProbability.hh"

G4O17GEMProbability::G4O17GEMProbability() :
  G4GEMProbability(17,9,5.0/2.0) // A,Z,Spin
{

  ExcitEnergies.push_back(870.81*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(179.2*picosecond);

  ExcitEnergies.push_back(3055.2*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(83.0E-3*picosecond);

  ExcitEnergies.push_back(3841.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(17.0E-3*picosecond);

  ExcitEnergies.push_back(4553.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(40.0*keV));

  ExcitEnergies.push_back(5086.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(95.0*keV));

  ExcitEnergies.push_back(5380.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(28.0*keV));

  ExcitEnergies.push_back(5698.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(3.4*keV));

  ExcitEnergies.push_back(5870.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(6.6*keV));

  ExcitEnergies.push_back(5940.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(32.0*keV));

  ExcitEnergies.push_back(6357.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(124.0*keV));

  ExcitEnergies.push_back(7168.7*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.5*keV));

  ExcitEnergies.push_back(7202.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(280.0*keV));

  ExcitEnergies.push_back(7383.1*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.6*keV));

  ExcitEnergies.push_back(7386.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(0.9*keV));

  ExcitEnergies.push_back(7560.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(500.0*keV));

  ExcitEnergies.push_back(7577.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1.0*keV));

  ExcitEnergies.push_back(7690.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(18.0*keV));

  ExcitEnergies.push_back(7956.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(90.0*keV));

  ExcitEnergies.push_back(7990.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(270.0*keV));

  ExcitEnergies.push_back(8070.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(85.0*keV));

  ExcitEnergies.push_back(8180.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(69.0*keV));

  ExcitEnergies.push_back(8200.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(60.0*keV));

  ExcitEnergies.push_back(8352.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(9.0*keV));

  ExcitEnergies.push_back(8410.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(4.0*keV));

  ExcitEnergies.push_back(8474.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(7.0*keV));

  ExcitEnergies.push_back(8508.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(5.0*keV));

  ExcitEnergies.push_back(8700.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(50.0*keV));

  ExcitEnergies.push_back(8898.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(101.0*keV));

  ExcitEnergies.push_back(8972.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(21.0*keV));

  ExcitEnergies.push_back(9148.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(4.0*keV));

  ExcitEnergies.push_back(9187.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(3.0*keV));

  ExcitEnergies.push_back(9201.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(5.5*keV));

  ExcitEnergies.push_back(9422.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(120.0*keV));

  ExcitEnergies.push_back(9493.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(15.0*keV));

  ExcitEnergies.push_back(9720.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(16.0*keV));

  ExcitEnergies.push_back(9775.0*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(25.0*keV));

  ExcitEnergies.push_back(9977.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(80.0*keV));

  ExcitEnergies.push_back(10178.0*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(40.0*keV));

  ExcitEnergies.push_back(10337.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(150.0*keV));

  ExcitEnergies.push_back(10490.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(75.0*keV));

  ExcitEnergies.push_back(10773.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(80.0*keV));

  ExcitEnergies.push_back(10910.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(57.0*keV));

  ExcitEnergies.push_back(11076.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(5.0*keV));

  ExcitEnergies.push_back(12946.0*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(6.0*keV));

  ExcitEnergies.push_back(14980.0*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(150.0*keV));

  ExcitEnergies.push_back(21.7E3*keV);
  ExcitSpins.push_back(5.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(750.0*keV));

  ExcitEnergies.push_back(22.1E3*keV);
  ExcitSpins.push_back(7.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(750.0*keV));

  ExcitEnergies.push_back(22.5E3*keV);
  ExcitSpins.push_back(3.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(1000.0*keV));

  ExcitEnergies.push_back(23.0E3*keV);
  ExcitSpins.push_back(1.0/2.0);
  ExcitLifetimes.push_back(hbar_Planck*log(2.0)/(400.0*keV));
}


G4O17GEMProbability::G4O17GEMProbability(const G4O17GEMProbability &) : G4GEMProbability()
{
  throw G4HadronicException(__FILE__, __LINE__, "G4O17GEMProbability::copy_constructor meant to not be accessable");
}




const G4O17GEMProbability & G4O17GEMProbability::
operator=(const G4O17GEMProbability &)
{
  throw G4HadronicException(__FILE__, __LINE__, "G4O17GEMProbability::operator= meant to not be accessable");
  return *this;
}


G4bool G4O17GEMProbability::operator==(const G4O17GEMProbability &) const
{
  return false;
}

G4bool G4O17GEMProbability::operator!=(const G4O17GEMProbability &) const
{
  return true;
}


