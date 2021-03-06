#ifndef VX_GEAMCM_H
#define VX_GEAMCM_H

#include <QtCore/qglobal.h>
#include <QtCore/qmath.h>

#include <QMatrix4x4>
#include <QVector>
#include <QVector2D>
#include <QVector3D>

#include <functional>

#include <assert.h>

#ifndef BUILD_STATIC
# if defined(VXGEAM_BUILD)
#  define VXGEAM_EXPORT Q_DECL_EXPORT
# else
#  define VXGEAM_EXPORT Q_DECL_IMPORT
# endif
#else
# define VXGEAM_EXPORT
#endif

#define VxZero (1.0e-6)

#define VxMin(a,b) (((a) < (b)) ? (a) : (b)) 

void GeMeshTri(int xStep,int yStep,QVector<QVector3D>& faceVertex,QVector<short>& faceIndex,std::function<QVector3D(int i, int j)> funcVertex,std::function<QVector3D(int i, int j)> funcNormal);

enum VeGeamType
{
    VeGeSphere,
    VeGeCylinder,
    VeGeCone,
    VeGeTypeLast
};

class VXGEAM_EXPORT VxGeam
{
public:
    VxGeam();
    virtual ~VxGeam();

public:
    virtual void triFace(QVector<QVector3D>& vertexFace, QVector<short>& indexFace, int xStep, int yStep) const = 0;

public:
    virtual QMatrix4x4 getXform()const = 0;
    virtual bool isect(const QVector3D& org, const QVector3D& dir, float& param) const = 0;

public:
    virtual VeGeamType type() const = 0;
};


#endif