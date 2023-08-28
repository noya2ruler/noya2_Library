#pragma once

#include"../template/template.hpp"

namespace noya2{

template<class S, S(*op)(S, S), S(*e)()>
struct dynamic_segtree {
    struct Node;
    using Ptr = shared_ptr<Node>;
    struct Node {
        S val;
        Ptr lch, rch, par;
        Node (Ptr par_ = nullptr) : val(e()), lch(nullptr), rch(nullptr), par(par_) {}
    };
    Ptr root;
    ll n;
    dynamic_segtree (ll n_ = 0) : n(2){
        while (n < n_) n <<= 1;
        root = make_shared<Node>();
    }
    void set(ll idx, S val_){
        assert(0 <= idx && idx < n);
        ll le = 0, ri = n;
        Ptr cur = root;
        while (ri - le > 1){
            ll md = (le + ri) / 2;
            if (idx < md){
                if (cur->lch == nullptr) cur->lch = make_shared<Node>(cur);
                cur = cur->lch;
                ri = md;
            }
            else {
                if (cur->rch == nullptr) cur->rch = make_shared<Node>(cur);
                cur = cur->rch;
                le = md;
            }
        }
        cur->val = val_;
        while (cur->par){
            cur = cur->par;
            cur->val = op(get(cur->lch),get(cur->rch));
        }
    }
    S prod(ll lid, ll rid){
        assert(0 <= lid && lid <= rid && rid <= n);
        if (lid == rid) return e();
        Ptr cur = root;
        ll le = 0, ri = n;
        while (ri - le > 1){
            ll md = (le + ri) / 2;
            if (lid < md && md < rid){
                if (lid == le && rid == ri) return cur->val;
                return op(prod_l(cur->lch,le,md,lid),prod_r(cur->rch,md,ri,rid));
            }
            if (rid <= md){
                if (cur->lch == nullptr) return e();
                cur = cur->lch;
                ri = md;
            }
            else {
                if (cur->rch == nullptr) return e();
                cur = cur->rch;
                le = md;
            }
        }
        return cur->val;
    }
    S get(Ptr ptr){
        if (ptr) return ptr->val;
        return e();
    }
    S prod_l(Ptr cur, ll le, ll ri, ll lid){
        S prd = e();
        while (cur){
            ll md = (le + ri) / 2;
            if (lid == le){
                prd = op(cur->val,prd);
                break;
            }
            if (lid < md){
                prd = op(get(cur->rch),prd);
                cur = cur->lch;
                ri = md;
            }
            else {
                cur = cur->rch;
                le = md;
            }
        }
        return prd;
    }
    S prod_r(Ptr cur, ll le, ll ri, ll rid){
        S prd = e();
        while (cur){
            ll md = (le + ri) / 2;
            if (rid == ri){
                prd = op(prd,cur->val);
                break;
            }
            if (rid > md){
                prd = op(prd,get(cur->lch));
                cur = cur->rch;
                le = md;
            }
            else {
                cur = cur->lch;
                ri = md;
            }
        }
        return prd;
    }
    S all_prod(){
        return root->val;
    }
    S get(ll idx){
        assert(0 <= idx && idx < n);
        ll le = 0, ri = n;
        Ptr cur = root;
        while (ri - le > 1){
            ll md = (le + ri) / 2;
            if (idx < md){
                if (cur->lch == nullptr) return e();
                cur = cur->lch;
                ri = md;
            }
            else {
                if (cur->rch == nullptr) return e();
                cur = cur->rch;
                le = md;
            }
        }
        return cur->val;
    }
};

} // namespace noya2