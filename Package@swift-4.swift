// swift-tools-version:4.0
import PackageDescription

let package = Package(
    name: "KittenCTLS",
    pkgConfig: "openssl",
    products: [
        .library(name: "KittenCTLS", targets: ["KittenCTLS"])
    ],
    targets: [
        .target(name: "KittenCTLS")
    ]
)
