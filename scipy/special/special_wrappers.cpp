#include "special_wrappers.h"
#include "special/airy.h"
#include "special/amos.h"
#include "special/binom.h"
#include "special/bessel.h"
#include "special/fresnel.h"
#include "special/hyp2f1.h"
#include "special/gamma.h"
#include "special/kelvin.h"
#include "special/mathieu.h"
#include "special/par_cyl.h"
#include "special/specfun.h"
#include "special/sph_harm.h"
#include "special/sphd_wave.h"
#include "special/struve.h"

#include "special/cephes/airy.h"
#include "special/cephes/beta.h"
#include "special/cephes/bdtr.h"
#include "special/cephes/ellpj.h"
#include "special/cephes/ellpk.h"
#include "special/cephes/expn.h"
#include "special/cephes/hyp2f1.h"
#include "special/cephes/fresnl.h"
#include "special/cephes/gamma.h"
#include "special/cephes/scipy_iv.h"
#include "special/cephes/jv.h"
#include "special/cephes/kolmogorov.h"
#include "special/cephes/nbdtr.h"
#include "special/cephes/ndtr.h"
#include "special/cephes/ndtri.h"
#include "special/cephes/pdtr.h"
#include "special/cephes/poch.h"
#include "special/cephes/polevl.h"
#include "special/cephes/sici.h"
#include "special/cephes/shichi.h"
#include "special/cephes/struve.h"
#include "special/cephes/unity.h"
#include "special/cephes/yn.h"

using namespace std;

namespace {

complex<double> to_complex(npy_cdouble z) {
    union {
        npy_cdouble cvalue;
        complex<double> value;
    } z_union{z};
    return z_union.value;
}

npy_cdouble to_ccomplex(complex<double> z) {
    union {
        complex<double> value;
        npy_cdouble cvalue;
    } z_union{z};
    return z_union.cvalue;
}

} // namespace

npy_cdouble chyp2f1_wrap(double a, double b, double c, npy_cdouble z) {
    return to_ccomplex(special::chyp2f1(a, b, c, to_complex(z)));
}

npy_cdouble chyp1f1_wrap(double a, double b, npy_cdouble z) {
    return to_ccomplex(special::chyp1f1(a, b, to_complex(z)));
}

double hypU_wrap(double a, double b, double x) { return special::hypu(a, b, x); }

double hyp1f1_wrap(double a, double b, double x) { return special::hyp1f1(a, b, x); }

void itairy_wrap(double x, double *apt, double *bpt, double *ant, double *bnt) {
    special::itairy(x, apt, bpt, ant, bnt);
}

double exp1_wrap(double x) { return special::exp1(x); }

npy_cdouble cexp1_wrap(npy_cdouble z) { return to_ccomplex(special::exp1(to_complex(z))); }

double expi_wrap(double x) { return special::expi(x); }

npy_cdouble cexpi_wrap(npy_cdouble z) { return to_ccomplex(special::expi(to_complex(z))); }

npy_cdouble cerf_wrap(npy_cdouble z) { return to_ccomplex(special::cerf(to_complex(z))); }

double itstruve0_wrap(double x) { return special::itstruve0(x); }

double it2struve0_wrap(double x) { return special::it2struve0(x); }

double itmodstruve0_wrap(double x) { return special::itmodstruve0(x); }

double ber_wrap(double x) { return special::ber(x); }

double bei_wrap(double x) { return special::bei(x); }

double ker_wrap(double x) { return special::ker(x); }

double kei_wrap(double x) { return special::kei(x); }

double berp_wrap(double x) { return special::berp(x); }

double beip_wrap(double x) { return special::beip(x); }

double kerp_wrap(double x) { return special::kerp(x); }

double keip_wrap(double x) { return special::keip(x); }

void kelvin_wrap(double x, npy_cdouble *Be, npy_cdouble *Ke, npy_cdouble *Bep, npy_cdouble *Kep) {
    special::kelvin(x, reinterpret_cast<complex<double> *>(Be), reinterpret_cast<complex<double> *>(Ke),
                    reinterpret_cast<complex<double> *>(Bep), reinterpret_cast<complex<double> *>(Kep));
}

npy_cdouble hyp2f1_complex_wrap(double a, double b, double c, npy_cdouble z) {
    return to_ccomplex(special::hyp2f1(a, b, c, to_complex(z)));
}

double binom_wrap(double n, double k) {
    return special::binom(n, k);
}

void it1j0y0_wrap(double x, double *j0int, double *y0int) { special::it1j0y0(x, j0int, y0int); }

void it2j0y0_wrap(double x, double *j0int, double *y0int) { special::it2j0y0(x, j0int, y0int); }

void it1i0k0_wrap(double x, double *i0int, double *k0int) { special::it1i0k0(x, i0int, k0int); }

void it2i0k0_wrap(double x, double *i0int, double *k0int) { special::it2i0k0(x, i0int, k0int); }

int cfresnl_wrap(npy_cdouble z, npy_cdouble *zfs, npy_cdouble *zfc) {
    special::cfresnl(to_complex(z), reinterpret_cast<complex<double> *>(zfs), reinterpret_cast<complex<double> *>(zfc));
    return 0;
}

double cem_cva_wrap(double m, double q) { return special::cem_cva(m, q); }

double sem_cva_wrap(double m, double q) { return special::sem_cva(m, q); }

void cem_wrap(double m, double q, double x, double *csf, double *csd) { special::cem(m, q, x, csf, csd); }

void sem_wrap(double m, double q, double x, double *csf, double *csd) { special::sem(m, q, x, csf, csd); }

void mcm1_wrap(double m, double q, double x, double *f1r, double *d1r) { special::mcm1(m, q, x, f1r, d1r); }

void msm1_wrap(double m, double q, double x, double *f1r, double *d1r) { special::msm1(m, q, x, f1r, d1r); }

void mcm2_wrap(double m, double q, double x, double *f2r, double *d2r) { special::mcm2(m, q, x, f2r, d2r); }

void msm2_wrap(double m, double q, double x, double *f2r, double *d2r) { special::msm2(m, q, x, f2r, d2r); }

double pmv_wrap(double m, double v, double x) { return special::pmv(m, v, x); }

void pbwa_wrap(double a, double x, double *wf, double *wd) { special::pbwa(a, x, wf, wd); }

void pbdv_wrap(double v, double x, double *pdf, double *pdd) { special::pbdv(v, x, pdf, pdd); }

void pbvv_wrap(double v, double x, double *pvf, double *pvd) { special::pbvv(v, x, pvf, pvd); }

double prolate_segv_wrap(double m, double n, double c) { return special::prolate_segv(m, n, c); }

double oblate_segv_wrap(double m, double n, double c) { return special::oblate_segv(m, n, c); }

double prolate_aswfa_nocv_wrap(double m, double n, double c, double x, double *s1d) {
    double s1f;
    special::prolate_aswfa_nocv(m, n, c, x, &s1f, s1d);

    return s1f;
}

double oblate_aswfa_nocv_wrap(double m, double n, double c, double x, double *s1d) {
    double s1f;
    special::oblate_aswfa_nocv(m, n, c, x, &s1f, s1d);

    return s1f;
}

void prolate_aswfa_wrap(double m, double n, double c, double cv, double x, double *s1f, double *s1d) {
    special::prolate_aswfa(m, n, c, cv, x, s1f, s1d);
}

void oblate_aswfa_wrap(double m, double n, double c, double cv, double x, double *s1f, double *s1d) {
    special::oblate_aswfa(m, n, c, cv, x, s1f, s1d);
}

double prolate_radial1_nocv_wrap(double m, double n, double c, double x, double *r1d) {
    double r1f;
    special::prolate_radial1_nocv(m, n, c, x, &r1f, r1d);

    return r1f;
}

double prolate_radial2_nocv_wrap(double m, double n, double c, double x, double *r2d) {
    double r2f;
    special::prolate_radial2_nocv(m, n, c, x, &r2f, r2d);

    return r2f;
}

void prolate_radial1_wrap(double m, double n, double c, double cv, double x, double *r1f, double *r1d) {
    special::prolate_radial1(m, n, c, cv, x, r1f, r1d);
}

void prolate_radial2_wrap(double m, double n, double c, double cv, double x, double *r2f, double *r2d) {
    special::prolate_radial2(m, n, c, cv, x, r2f, r2d);
}

double oblate_radial1_nocv_wrap(double m, double n, double c, double x, double *r1d) {
    double r1f;
    special::oblate_radial1_nocv(m, n, c, x, &r1f, r1d);

    return r1f;
}

double oblate_radial2_nocv_wrap(double m, double n, double c, double x, double *r2d) {
    double r2f;
    special::oblate_radial2_nocv(m, n, c, x, &r2f, r2d);

    return r2f;
}

void oblate_radial1_wrap(double m, double n, double c, double cv, double x, double *r1f, double *r1d) {
    special::oblate_radial1(m, n, c, cv, x, r1f, r1d);
}

void oblate_radial2_wrap(double m, double n, double c, double cv, double x, double *r2f, double *r2d) {
    special::oblate_radial2(m, n, c, cv, x, r2f, r2d);
}

void modified_fresnel_plus_wrap(double x, npy_cdouble *Fplus, npy_cdouble *Kplus) {
    special::modified_fresnel_plus(x, reinterpret_cast<complex<double> *>(Fplus),
                                   reinterpret_cast<complex<double> *>(Kplus));
}

void modified_fresnel_minus_wrap(double x, npy_cdouble *Fminus, npy_cdouble *Kminus) {
    special::modified_fresnel_minus(x, reinterpret_cast<complex<double> *>(Fminus),
                                    reinterpret_cast<complex<double> *>(Kminus));
}

double sin_pi(double x) { return special::sin_pi(x); }

double cos_pi(double x) { return special::cos_pi(x); }

void airy_wrap(double x, double *ai, double *aip, double *bi, double *bip) { special::airy_wrap(x, ai, aip, bi, bip); }

void cairy_wrap(npy_cdouble z, npy_cdouble *ai, npy_cdouble *aip, npy_cdouble *bi, npy_cdouble *bip) {
    special::cairy_wrap(to_complex(z), reinterpret_cast<complex<double> *>(ai),
                        reinterpret_cast<complex<double> *>(aip), reinterpret_cast<complex<double> *>(bi),
                        reinterpret_cast<complex<double> *>(bip));
}

void cairy_wrap_e(npy_cdouble z, npy_cdouble *ai, npy_cdouble *aip, npy_cdouble *bi, npy_cdouble *bip) {
    special::cairy_wrap_e(to_complex(z), reinterpret_cast<complex<double> *>(ai),
                          reinterpret_cast<complex<double> *>(aip), reinterpret_cast<complex<double> *>(bi),
                          reinterpret_cast<complex<double> *>(bip));
}

void cairy_wrap_e_real(double z, double *ai, double *aip, double *bi, double *bip) {
    special::cairy_wrap_e_real(z, ai, aip, bi, bip);
}

npy_cdouble cbesi_wrap(double v, npy_cdouble z) { return to_ccomplex(special::cbesi_wrap(v, to_complex(z))); }

npy_cdouble cbesi_wrap_e(double v, npy_cdouble z) { return to_ccomplex(special::cbesi_wrap_e(v, to_complex(z))); }

double cbesi_wrap_e_real(double v, double z) { return special::cbesi_wrap_e_real(v, z); }

npy_cdouble cbesj_wrap(double v, npy_cdouble z) { return to_ccomplex(special::cbesj_wrap(v, to_complex(z))); }

double cbesj_wrap_real(double v, double x) { return special::cbesj_wrap_real(v, x); }

npy_cdouble cbesj_wrap_e(double v, npy_cdouble z) { return to_ccomplex(special::cbesj_wrap_e(v, to_complex(z))); }

double cbesj_wrap_e_real(double v, double z) { return special::cbesj_wrap_e_real(v, z); }

npy_cdouble cbesy_wrap(double v, npy_cdouble z) { return to_ccomplex(special::cbesy_wrap(v, to_complex(z))); }

double cbesy_wrap_real(double v, double x) { return special::cbesy_wrap_real(v, x); }

npy_cdouble cbesy_wrap_e(double v, npy_cdouble z) { return to_ccomplex(special::cbesy_wrap_e(v, to_complex(z))); }

double cbesy_wrap_e_real(double v, double z) { return special::cbesy_wrap_e_real(v, z); }

npy_cdouble cbesk_wrap(double v, npy_cdouble z) { return to_ccomplex(special::cbesk_wrap(v, to_complex(z))); }

npy_cdouble cbesk_wrap_e(double v, npy_cdouble z) { return to_ccomplex(special::cbesk_wrap_e(v, to_complex(z))); }

double cbesk_wrap_real(double v, double z) { return special::cbesk_wrap_real(v, z); }

double cbesk_wrap_real_int(int n, double z) { return special::cbesk_wrap_real_int(n, z); }

double cbesk_wrap_e_real(double v, double z) { return special::cbesk_wrap_e_real(v, z); }

npy_cdouble cbesh_wrap1(double v, npy_cdouble z) { return to_ccomplex(special::cbesh_wrap1(v, to_complex(z))); }

npy_cdouble cbesh_wrap1_e(double v, npy_cdouble z) { return to_ccomplex(special::cbesh_wrap1_e(v, to_complex(z))); }

npy_cdouble cbesh_wrap2(double v, npy_cdouble z) { return to_ccomplex(special::cbesh_wrap2(v, to_complex(z))); }

npy_cdouble cbesh_wrap2_e(double v, npy_cdouble z) { return to_ccomplex(special::cbesh_wrap2_e(v, to_complex(z))); }

npy_cdouble special_sph_harm(long m, long n, double theta, double phi) {
    return to_ccomplex(special::sph_harm(m, n, theta, phi));
}

npy_cdouble special_sph_harm_unsafe(double m, double n, double theta, double phi) {
    return to_ccomplex(special::sph_harm(static_cast<long>(m), static_cast<long>(n), theta, phi));
}

double cephes_hyp2f1_wrap(double a, double b, double c, double x) {
    return special::cephes::hyp2f1(a, b, c, x);
}

double cephes_airy_wrap(double x, double *ai, double *aip, double *bi, double *bip) {
    return special::cephes::airy(x, ai, aip, bi, bip);
}

double cephes_beta_wrap(double a, double b) {
    return special::cephes::beta(a, b);
}

double cephes_lbeta_wrap(double a, double b) {
    return special::cephes::lbeta(a, b);
}

double cephes_bdtr_wrap(double k, int n, double p) {
    return special::cephes::bdtr(k, n, p);
}

double cephes_bdtri_wrap(double k, int n, double y) {
    return special::cephes::bdtri(k, n, y);
}

double cephes_bdtrc_wrap(double k, int n, double p) {
    return special::cephes::bdtrc(k, n, p);
}

double cephes_cosm1_wrap(double x) {
    return special::cephes::cosm1(x);
}

double cephes_expm1_wrap(double x) {
    return special::cephes::expm1(x);
}

double cephes_expn_wrap(int n, double x) {
    return special::cephes::expn(n, x);
}

double cephes_log1p_wrap(double x) {
    return special::cephes::log1p(x);
}

double cephes_gamma_wrap(double x) {
    return special::cephes::Gamma(x);
}

double cephes_gammasgn_wrap(double x) {
    return special::cephes::gammasgn(x);
}

double cephes_lgam_wrap(double x) {
    return special::cephes::lgam(x);
}

double cephes_iv_wrap(double v, double x) {
    return special::cephes::iv(v, x);
}

double cephes_jv_wrap(double v, double x) {
    return special::cephes::jv(v, x);
}

int cephes_ellpj_wrap(double u, double m, double *sn, double *cn, double *dn, double *ph) {
    return special::cephes::ellpj(u, m, sn, cn, dn, ph);
}

double cephes_ellpk_wrap(double x) {
    return special::cephes::ellpk(x);
}

int cephes_fresnl_wrap(double xxa, double *ssa, double *cca) {
    return special::cephes::fresnl(xxa, ssa, cca);
}

double cephes_nbdtr_wrap(int k, int n, double p) {
    return special::cephes::nbdtr(k, n, p);
}

double cephes_nbdtrc_wrap(int k, int n, double p) {
    return special::cephes::nbdtrc(k, n, p);
}

double cephes_nbdtri_wrap(int k, int n, double p) {
    return special::cephes::nbdtri(k, n, p);
}

double cephes_ndtr_wrap(double x) {
    return special::cephes::ndtr(x);
}

double cephes_ndtri_wrap(double x) {
    return special::cephes::ndtri(x);
}

double cephes_pdtri_wrap(int k, double y) {
    return special::cephes::pdtri(k, y);
}

double cephes_poch_wrap(double x, double m) {
    return special::cephes::poch(x, m);
}

int cephes_sici_wrap(double x, double *si, double *ci){
    return special::cephes::sici(x, si, ci);
}

int cephes_shichi_wrap(double x, double *si, double *ci){
    return special::cephes::shichi(x, si, ci);
}

double cephes_smirnov_wrap(int n, double x) {
    return special::cephes::smirnov(n, x);
}

double cephes_smirnovc_wrap(int n, double x) {
    return special::cephes::smirnovc(n, x);
}

double cephes_smirnovi_wrap(int n, double x) {
    return special::cephes::smirnovi(n, x);
}

double cephes_smirnovci_wrap(int n, double x) {
    return special::cephes::smirnovci(n, x);
}

double cephes_smirnovp_wrap(int n, double x) {
    return special::cephes::smirnovp(n, x);
}

double cephes__struve_asymp_large_z(double v, double z, int is_h, double *err) {
    return special::cephes::detail::struve_asymp_large_z(v, z, is_h, err);
}

double cephes__struve_bessel_series(double v, double z, int is_h, double *err) {
    return special::cephes::detail::struve_bessel_series(v, z, is_h, err);
}

double cephes__struve_power_series(double v, double z, int is_h, double *err) {
    return special::cephes::detail::struve_power_series(v, z, is_h, err);
}

double cephes_yn_wrap(int n, double x) {
    return special::cephes::yn(n, x);
}
    
double cephes_polevl_wrap(double x, const double coef[], int N) {
    return special::cephes::polevl(x, coef, N);
}

double cephes_p1evl_wrap(double x, const double coef[], int N) {
    return special::cephes::p1evl(x, coef, N);
}

double gammaln_wrap(double x) { return special::gammaln(x); }
