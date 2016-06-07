// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4FConicalSurface.cc,v 2.16 1998/12/10 17:26:41 broglia Exp $
// GEANT4 tag $Name: geant4-00 $
//
/*  /usr/local/gismo/repo/geometry/G4FConicalSurface.cc,v 1.2 1993/02/05 00:38:39 alanb Exp  */
//  File:  G4FConicalSurface.cc
//  Author:  Alan Breakstone

//  Contents ----------------------------------------------------------
//
//      G4FConicalSurface::G4FConicalSurface( const G4Point3D& o, 
//                                            const G4Vector3D& a,
//		G4double l, G4double sr, G4double lr )
//	G4FConicalSurface::G4FConicalSurface( const G4FConicalSurface& c )
//	G4FConicalSurface::PrintOn( ostream& os ) const
//	G4FConicalSurface::operator==( const G4FConicalSurface& c )
//	G4FConicalSurface::WithinBoundary( const G4Vector3D& x ) const
//	G4FConicalSurface::Scale() const
//	G4FConicalSurface::Area() const
//	G4FConicalSurface::resize( G4double l, G4double sr, G4double lr )
//
//  End ---------------------------------------------------------------

#include "G4FConicalSurface.hh"
#include "G4Sort.hh"
#include "G4CircularCurve.hh"


G4FConicalSurface::G4FConicalSurface(const G4Point3D&  o, 
				     const G4Vector3D& a,
				     G4double          l, 
				     G4double          sr, 
				     G4double          lr 
				    ) //: G4ConicalSurface( o, a, 1.0 )
                                      //: G4Surface( o ) doesn`t exist
{
  //  Make a G4FConicalSurface with origin o, axis a, length l, small radius 
  //  sr, and large radius lr. The angle is calculated below and the SetAngle
  //  function of G4ConicalSurface is used to set it properly from the default
  // value used above in the initialization.
 
  // L. Broglia
  // Position.SetSrfPoint(o);
  // Position.SetAxis(a);
  // Create the position with origin o, axis a, and a direction wich
  // is not important
  G4Vector3D dir(1,1,1);
  Position.Init(dir, a, o);
  origin = o;
  
  //  Require length to be nonnegative
  //	if ( l > 0.0 )
  if (l >=0)
    length = l;
  else 
  {
    G4cerr << "Error in G4FConicalSurface::G4FConicalSurface"
	   << "--asked for negative length\n"
	   << "\tDefault length of 0.0 is used.\n";
   
    length = 0.0;
  }
  
  //  Require small radius to be non-negative (i.e., allow zero)
  if ( sr >= 0.0 )
    small_radius = sr;
  else 
  {
    G4cerr << "Error in G4FConicalSurface::G4FConicalSurface"
	   << "--asked for negative small radius\n"
	   << "\tDefault value of 0.0 is used.\n";
   
    small_radius = 0.0;
  }

  //  Require large radius to exceed small radius
  if ( lr > small_radius )
    large_radius = lr;
  else 
  {
    G4cerr << "Error in G4FConicalSurface::G4FConicalSurface"
	   << "--large radius must exceed small radius\n"
	   << "\tDefault value of small radius +1 is used.\n";
   
    large_radius = small_radius + 1.0;
  }

  //  Calculate the angle of the G4ConicalSurface from the length and radii
  tan_angle =  ( large_radius - small_radius ) / length ;
}


G4FConicalSurface::G4FConicalSurface( const G4FConicalSurface& c )
  //: G4ConicalSurface( c.origin, c.GetAxis(), c.GetAngle() )
{ 
  //  copy constructor
  small_radius = c.small_radius;
  large_radius = c.large_radius;
  length       = c.length;
  tan_angle    = c.tan_angle;
}


// Modified by L. Broglia (01/12/98)
void G4FConicalSurface::CalcBBox()
{
  G4Point3D Max   = -PINFINITY;
  G4Point3D Min   =  PINFINITY;
  G4Point3D Tmp;
  G4double  delta = small_radius / tan_angle;

  G4Point3D Origin    = Position.GetLocation();
  G4Point3D EndOrigin = Origin + (length * Position.GetAxis());
  
  G4double radius = large_radius;
  G4Point3D Radius(radius, radius, 0);

  // Default BBox
  G4Point3D Tolerance(kCarTolerance, kCarTolerance, kCarTolerance);
  G4Point3D BoxMin(Origin-Tolerance);
  G4Point3D BoxMax(Origin+Tolerance);

  bbox = new G4BoundingBox3D();
  bbox->Init(BoxMin, BoxMax);

  Tmp = (Origin - Radius);
  bbox->Extend(Tmp);
  
  Tmp = Origin + Radius;
  bbox->Extend(Tmp);

  Tmp = EndOrigin - Radius;
  bbox->Extend(Tmp);
  
  Tmp = EndOrigin + Radius;
  bbox->Extend(Tmp);
}


void G4FConicalSurface::PrintOn( ostream& os ) const
{ 
  //  printing function using C++ ostream class
  os << "G4FConicalSurface with origin: " << origin << "\t"
     << "and axis: " << Position.GetAxis() << "\n"
     << "\t small radius: " << small_radius 
     << "\t large radius: " << large_radius
     << "\t and length: " << length << "\n";
}


int G4FConicalSurface::operator==( const G4FConicalSurface& c )
{
  return ( origin             == c.origin                &&
	   Position.GetAxis() == c.Position.GetAxis()    &&
	   small_radius       == c.small_radius          && 
	   large_radius       == c.large_radius          && 
	   length      	      == c.length                &&
	   tan_angle          == c.tan_angle                );
}


int G4FConicalSurface::WithinBoundary( const G4Vector3D& x ) const
{ 
  //  return 1 if point x is within the boundaries of the G4FConicalSurface
  //  return 0 otherwise (assume it is on the G4ConicalSurface)
  G4Vector3D q = x - origin;
  
  G4double qmag = q.mag();
  G4double s    = sin( atan2(large_radius-small_radius, length) );
  G4double ls   = small_radius / s;
  G4double ll   = large_radius / s;
  
  if ( ( qmag >= ls )  &&  ( qmag <= ll ) )
    return 1;
  else
    return 0;
}


G4double G4FConicalSurface::Scale() const
{  
  //  Returns the small radius of a G4FConicalSurface unless it is zero, in 
  //  which case returns the large radius.
  //  Used for Scale-invariant tests of surface thickness.
  if ( small_radius == 0.0 )
    return large_radius;
  else
    return small_radius;
}


G4double G4FConicalSurface::Area() const
{ 
 //  Returns the Area of a G4FConicalSurface
  G4double rdif = large_radius - small_radius; 
  
  return ( M_PI * ( small_radius + large_radius ) * 
	   sqrt( length * length  +  rdif * rdif ) );
}


void G4FConicalSurface::resize( G4double l, G4double sr, G4double lr )
{
  //  Resize a G4FConicalSurface to a new length l, and new radii sr and lr.
  //  Must Reset angle of the G4ConicalSurface as well based on these new 
  //  values.
  //  Require length to be non-negative
  
  //	if ( l > 0.0 )
  if ( l >= 0.0 )
    length = l;
  else 
  {
    G4cerr << "Error in G4FConicalSurface::resize"
	   << "--asked for negative length\n"
	   << "\tOriginal value of " << length << " is retained.\n";
  }

  //  Require small radius to be non-negative (i.e., allow zero)
  if ( sr >= 0.0 )
    small_radius = sr;
  else 
  {
    G4cerr << "Error in G4FConicalSurface::resize"
	   << "--asked for negative small radius\n"
	   << "\tOriginal value of " << small_radius
	   << " is retained.\n";
  }

  //  Require large radius to exceed small radius
  if ( lr > small_radius )
    large_radius = lr;
  else 
  {
    G4double r = small_radius + 1.0;
    lr = ( large_radius <= small_radius ) ? r : large_radius;
    large_radius = lr;
    
    G4cerr << "Error in G4FConicalSurface::G4FConicalSurface"
	   << "--large radius must exceed small radius\n"
	   << "\tDefault value of " << large_radius << " is used.\n";
  }

  //  Calculate the angle of the G4ConicalSurface from the length and radii
  tan_angle =  ( large_radius - small_radius ) / length ;
 
}


int G4FConicalSurface::Intersect(const G4Ray& ry )
{ 
  //  Distance along a Ray (straight line with G4Vector3D) to leave or enter
  //  a G4FConicalSurface.  The input variable which_way should be set to +1 to
  //  indicate leaving a G4ConicalSurface, -1 to indicate entering a 
  //  G4ConicalSurface.
  //  p is the point of intersection of the Ray with the G4ConicalSurface.
  //  If the G4Vector3D of the Ray is opposite to that of the Normal to
  //  the G4FConicalSurface at the intersection point, it will not leave the 
  //  G4FConicalSurface.
  //  Similarly, if the G4Vector3D of the Ray is along that of the Normal 
  //  to the G4ConicalSurface at the intersection point, it will not enter the
  //  G4ConicalSurface.
  //  This method is called by all finite shapes sub-classed to 
  //  G4ConicalSurface.
  //  Use the virtual function table to check if the intersection point
  //  is within the boundary of the finite shape.
  //  A negative result means no intersection.
  //  If no valid intersection point is found, set the distance
  //  and intersection point to large numbers.
 
  int which_way;
 
  if(Inside(ry.GetStart()))
    which_way = 1;
  else
    which_way = -1;	   
  
  distance = FLT_MAXX;

  G4Vector3D lv ( FLT_MAXX, FLT_MAXX, FLT_MAXX );
  closest_hit = lv;

  //  Origin and G4Vector3D unit vector of Ray.

  G4Vector3D x    = ry.GetStart();
  G4Vector3D dhat = ry.GetDir();

  //  Cone angle and axis unit vector.
  G4double ta = tan_angle;
  G4Vector3D ahat = Position.GetAxis();
  int isoln = 0, maxsoln = 2;
 
  //  array of solutions in distance along the Ray
  G4double s[2];
  s[0]=-1.0;
  s[1]=-1.0;

  // L. Broglia
  //  calculate the two solutions (quadratic equation)
    
  G4Vector3D gamma =  x - Position.GetLocation();
  
  G4double T  = 1.0  +  ta * ta;
  G4double ga = gamma * ahat;
  G4double da = dhat * ahat;
  /*
  G4double A  = 1.0 - T * da * da;
  G4double B  = 2.0 * ( gamma * dhat - T * ga * da );
  G4double C  = gamma * gamma - T * ga * ga;
  */

  G4double A = - 1.0 + T * da * da;
  G4double B = 2 * ( -gamma * dhat + T * ga * da - large_radius * ta * da);
  G4double C = ( -gamma * gamma + T * ga * ga 
		 - 2 * large_radius * ta * ga
		 + large_radius * large_radius );


  //  if quadratic term vanishes, just do the simple solution
  if ( fabs( A ) < FLT_EPSILO ) 
    if ( B == 0.0 )
      return 1;
    else
      s[0] = -C / B;
  
  //  Normal quadratic case, no intersection if radical is less than zero
  else 
  {
    G4double radical = B * B  -  4.0 * A * C; 

    if ( radical < 0.0 ) 
      return 0;
    else 
    {
      G4double root = sqrt( radical );
      s[0] = ( - B + root ) / ( 2. * A );
      s[1] = ( - B - root ) / ( 2. * A );
    }
  }



  

  //  order the possible solutions by increasing distance along the Ray
  //  (G4Sorting routines are in support/G4Sort.h)
  G4Sort_double( s, isoln, maxsoln-1 );

  //  now loop over each positive solution, keeping the first one (smallest
  //  distance along the Ray) which is within the boundary of the sub-shape
  //  and which also has the correct G4Vector3D with respect to the Normal to
  //  the G4ConicalSurface at the intersection point
  for ( isoln = 0; isoln < maxsoln; isoln++ ) 
  {
    if ( s[isoln] >= kCarTolerance*0.5 ) 
    {
      if ( s[isoln] >= FLT_MAXX )  // quit if too large
	return 0;
      
      distance = s[isoln];
      closest_hit = ry.GetPoint( distance );
      

      //  Following line necessary to select non-reflective solutions.
      if ((( ahat * ( closest_hit - Position.GetLocation() ) > 0.0 )       && 
	   ((( dhat * SurfaceNormal( closest_hit ) * which_way ) >= 0.0 )) &&
	   ( fabs(HowNear( closest_hit )) < 0.1))                             )
      {
	if ( WithinBoundary ( closest_hit ) == 1 ) 
	{
	  distance =  distance*distance;
	  return 1;
	}	
      }
      distance =  distance*distance;
      return 1;
    }
    else
      if ( s[isoln] >= -kCarTolerance*0.5 ) 
      {
	// the point is on the surface
	distance = 0;
	return 1;
      }   
  }

  //  get here only if there was no solution within the boundary, Reset
  //  distance and intersection point to large numbers
  distance = FLT_MAXX;
  closest_hit = lv;
  
  return 0;
}


G4double G4FConicalSurface::HowNear( const G4Vector3D& x ) const
{ 
  // Distance from the point x to the semi-infinite G4FConicalSurface.
  // The distance will be positive if the point is Inside the G4ConicalSurface,
  // negative if the point is outside.
  // Note that this may not be correct for a bounded conical object
  // subclassed to G4ConicalSurface.
  
  G4Vector3D d       = x - origin;
  G4double   dA      = d * Position.GetAxis();
  G4double   rad     = sqrt( d.mag2() - dA*dA );
  G4double   teta    = atan2( (large_radius - small_radius) , length );
  G4double   radiu   = fabs( rad - large_radius + dA*tan_angle );
  G4double   hownear ;

  if (dA > length)
    hownear =dA - length;
  else if (dA < 0)
    hownear =dA;
  else
    hownear = radiu * cos(teta);

  return hownear;
}


// Add by L. Broglia
// Verify this function
G4Vector3D G4FConicalSurface::SurfaceNormal( const G4Point3D& p ) const
{  
  //  return the Normal unit vector to the G4ConicalSurface at a point p 
  //  on (or nearly on) the G4ConicalSurface
  G4Vector3D s    = p - origin;
  G4double   smag = s.mag2();
  
  //  if the point happens to be at the origin, calculate a unit vector Normal
  //  to the axis, with zero z component
  if ( smag == 0.0 )
  {
    G4double ax = Position.GetAxis().x();
    G4double ay = Position.GetAxis().y();
    G4double ap = sqrt( ax * ax  +  ay * ay );

    if ( ap == 0.0 )
      return G4Vector3D( 1.0, 0.0, 0.0 );
    else
      return G4Vector3D( ay / ap, -ax / ap, 0.0 );
  }

  //  otherwise do the calculation of the Normal to the conical surface
  else 
  {
    G4double l = s * Position.GetAxis();

    s = s*(1/smag);
    G4Vector3D q    = origin  +  l * Position.GetAxis();
    G4Vector3D v    = p - q;

    G4double   sl   = v.mag2() * 
      sin( atan2((large_radius - small_radius), length) );
    
    G4Vector3D n    = v - sl * s;

    G4double   nmag = n.mag2(); 

    if ( nmag != 0.0 )
      n=n*(1/nmag);
    
    return n;
  }
}

// Add by L. Broglia
int G4FConicalSurface::Inside ( const G4Vector3D& x ) const
{ 
  // Return 0 if point x is outside G4ConicalSurface, 1 if Inside.
  // Outside means that the distance to the G4ConicalSurface would be negative.
  // Use the HowNear function to calculate this distance.
  if ( HowNear( x ) >= -0.5*kCarTolerance )
    return 1;
  else
    return 0; 
}



